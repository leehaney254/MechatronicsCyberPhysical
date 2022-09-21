#include <stm32f4xx.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void SPI1_Config(void);
void SPI1_Receive(uint8_t *data, int size);
void SPI1_CS_Enable(void);
void SPI1_CS_Disable(void);
void SPI1_Enable(void);
void DMA2_STREAM0_Config(void);
void startSPI1_RX_DMA (uint32_t SOURCE_ADDRESS, uint32_t DESTINATION_ADDRESS, uint32_t LENGTH);
void SysClockConfig(void);
int hextodc(char *hex);



char receiv[3];
uint8_t lee;
uint8_t num2 = 7;
int i;



int main()
{
	SysClockConfig();
	SPI1_Config();
	
	DMA2_STREAM0_Config();
	startSPI1_RX_DMA((uint32_t)&(SPI1->DR), (uint32_t)receiv, sizeof(receiv));

	
	while(1)
	{
		lee = atoi(receiv);
		if(lee == 15)
		{
			GPIOB->BSRR |= GPIO_BSRR_BS5;
		}
		else
		{
			GPIOB->BSRR |= GPIO_BSRR_BR5;
		}
	}
}


int hextodc(char *hex){
   int y = 0;
   int dec = 0;
   int x, i;
   for(i = strlen(hex) - 1 ; i >= 0 ; --i){
      if(hex[i]>='0'&&hex[i]<='9'){
         x = hex[i] - '0';
      }
      else{
         x = hex[i] - 'A' + 10;
      }
      dec = dec + x * pow(16 , y);// converting hexadecimal to integer value ++y;
		}
   return dec;
}


void SPI1_Config(void)
{

	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; //SPIL PERIPHERAL CLOCK ENABLE
	SPI1->CR1 |= SPI_CR1_CPOL;
	SPI1->CR1 |= SPI_CR1_CPHA;
	SPI1->CR1 &= ~SPI_CR1_MSTR; //SPII CONFIGURED AS SLAVE
	SPI1->CR1 &= ~SPI_CR1_LSBFIRST;  //MSB TRANSMITTED FIRST
	SPI1->CR1 &= ~SPI_CR1_RXONLY; 	//FULL DUPLEX (TRANSMIT AND RECEIVE)
	SPI1->CR1 &= ~SPI_CR1_DFF;	//8-BIT DATA FRAME FORMAT
		

	SPI1->CR2 = 0;
	SPI1->CR1 |= SPI_CR1_SPE;	//SPIL ENABLE
	SPI1->CR2 |= SPI_CR2_RXDMAEN;	//RX BUFFER DMA ENABLE
	//config
	RCC->AHB1ENR |= (1<<0);  // Enable GPIO Clock
	GPIOA->MODER |= (2<<10)|(2<<12)|(2<<14)|(1<<8);  // Alternate functions for PA5, PA6, PA7 and Output for PA4
	GPIOA->OSPEEDR |= (3<<10)|(3<<12)|(3<<14)|(3<<8);  // HIGH Speed for PA5, PA6, PA7, PA4
	GPIOA->AFR[0] |= (5<<20)|(5<<24)|(5<<28);   // AF5(SPI1) for PA5, PA6, PA7
	SPI1->CR1 |= (1<<6);//SPE=0, peripheral enabled
	
	
	RCC->AHB1ENR |= (1<<1);  // Enable GPIO Clock B
	GPIOB->MODER |= GPIO_MODER_MODE5_0;//01
	GPIOB->OTYPER &=  ~GPIO_OTYPER_OT5;//0 PUSH-PULL
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;//11
}


void SPI1_Receive(uint8_t *data, int size)
{
	while (size)
	{
		while(((SPI1->SR) & (1<<7))){};  //WAIT FOR BSY BIT TO RESET
		SPI1->DR= 0; //SEND DUMMY DATA 
		while (!((SPI1->SR) & (1<<0))){}; //WAIT FOR RXNE TO RESET
		*data++ = SPI1->DR;
		size--;
	}
}


void SPI1_CS_Enable(void)
{
	GPIOA->BSRR &= ~GPIO_BSRR_BR4;
}

void SPI1_CS_Disable(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BR4;
}

void SPI1_Enable(void)
{
  SPI1->CR1 |= SPI_CR1_SPE;	//SPI1 ENABLE
}



void DMA2_STREAM0_Config(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN; //DMA2 CLOCK ENABLE
	//DISABLE DMA STREAM TO START OFF
	DMA2_Stream0->CR &= ~DMA_SxCR_EN;//STREAM DISABLED
	while(((DMA2_Stream0->CR) & 0x1) == 0x1); //WAIT UNTIL DMA STREAM IS DISABLED

	//CLEAR ALL THE SETTINGS
	DMA2_Stream0->CR &= ~((0x7FUL<<21) | (0xFUL<<16) | (0x1FFUL<<6));

	//APPLY DMA SETTINGS
	//CHANNEL 3 SELECTED
	DMA2_Stream0->CR |= (DMA_SxCR_CHSEL_0 | DMA_SxCR_CHSEL_1);
	DMA2_Stream0->CR &= ~DMA_SxCR_CHSEL_2;
	//DATA TRANSFER DIRECTION SET TO PERIFERAL TO MEMORY
	DMA2_Stream0->CR &= ~DMA_SxCR_DIR;

	DMA2_Stream0->CR &= ~DMA_SxCR_PINC;		//PERIPHERAL INCREMENT DISABLED
	DMA2_Stream0->CR |= DMA_SxCR_MINC;		//MEMORY INCREMENT ENABLED
	DMA2_Stream0->CR &= ~(DMA_SxCR_MSIZE_0 | DMA_SxCR_MSIZE_1);	//MSIZE 8 BIT
	DMA2_Stream0->CR &= ~(DMA_SxCR_PSIZE_0	| DMA_SxCR_PSIZE_1);//PSIZE 8 BIT
	DMA2_Stream0->CR |= DMA_SxCR_CIRC;		//CIRCULAR MODE ENABLED
	DMA2_Stream0->CR &= ~DMA_SxCR_PL;			//PRIORITY LEVEL LOW
	DMA2_Stream0->FCR &= ~DMA_SxFCR_DMDIS; //DIRECT MODE ENABLED (FIFO DISABLED)


	NVIC_EnableIRQ (DMA2_Stream0_IRQn);
	NVIC_SetPriority (DMA2_Stream0_IRQn, 0);
}

void startSPI1_RX_DMA (uint32_t SOURCE_ADDRESS, uint32_t DESTINATION_ADDRESS, uint32_t LENGTH)
{
	DMA2_Stream0->CR &= ~DMA_SxCR_DBM; //CLEAR DBM BIT
	DMA2_Stream0->NDTR = LENGTH;			//NUMBER OF DATA TO TRANSFER (DMA DATA LENGTH)
	DMA2_Stream0->PAR =SOURCE_ADDRESS; //store address of (SPI1->DR) into (PAR) register (DATA SOURCE ADDRESS) 
	DMA2_Stream0->M0AR	= DESTINATION_ADDRESS; //store address of (RX_String) into (MOAR) register (DESTINATION ADDRESS)

	DMA2->HIFCR = (0x3DUL << 0);			//CLEAR ALL STREAM INTERRUPT FLAGS
	DMA2_Stream0->CR |= DMA_SxCR_TCIE;	//TRANSFER COMPLETE INTERRUPT ENABLE
	DMA2_Stream0->CR |= DMA_SxCR_EN;		//DMA STREAM ENABLE
	
	for (int j=0; j< 5000000; j++);

}

//INTERRUPT SERVICE ROUTINE
void DMA2_Stream0_IRQHandler (void)
{
	if (DMA2->LISR & DMA_LISR_TCIF0 && DMA2_Stream0->CR & DMA_SxCR_TCIE)
	{
		//NavCompRdy = 1; //INDICATE THAT NAVIGATION DATA IS PRESENT 
		DMA2->LIFCR = DMA_LIFCR_CTCIF0;	//ACKNOWLEDGE INTERRUPT ON STREAM O
	}
}

void SysClockConfig(void)
{
	#define PLL_M		12
	#define PLL_N		96
	#define PLL_P		0		//PLL_P = 2
	
	//ENABLE HSE AND WAIT FOR IT TO BECOME READY
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	//SET THE POWER ENABLE CLOCK AND VOLTAGE REGULATOR
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_VOS;
	
	//CONFIGURE FLASH PREFETCH AND THE LATENCY RELATED SETTINGS
	FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS;
	
	//CONFIGURE THE PRESCALARS HCLK, PCLK1, PCLK2
	//AHB PRESCALAR
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	//APB1 PRESCALAR
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
	//APB2 PRESCALAR
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
	
	//CONFIGURE THE MAIN PLL
	RCC->PLLCFGR &= ~( (1<<4) | (1<<12) | (1<<13) );	//CLEAR BITS 4, 12 AND 13 BECAUSE THEY ARE SET BBY DEFAULT
	RCC->PLLCFGR |= (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | (RCC_PLLCFGR_PLLSRC_HSE);
	
	//ENABLE PLL AND WAIT FOR IT TO BECOME READY
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	//SELECT THE CLOCK SOURCE AND WAIT FOR IT TO BE SET
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
	
	SystemCoreClockUpdate();
}
