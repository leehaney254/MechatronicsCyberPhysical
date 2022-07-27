const scene = new THREE.Scene(); //creating a scene
const camera = new THREE.PerspectiveCamera(100, window.innerWidth / window.innerHeight, 2, 20000);

const renderer = new THREE.WebGLRenderer(); //creating a renderer

let light;
let droneMesh;

//initialization function ya kuset background colour, camera postion na ku render
function init() {
    //Must have code  
    scene.background = new THREE.Color('gray');
    //camera.position.z =  30;
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);
    //camera.position.set(30, 50, 20);
    //renderer.setPixelRatio(window.devicePixelRatio);
    //initialCameraFOV = camera.fov;
    //make the camera somewhat responsive
    //window.addEventListener('resize', onWindowResize, false);
    //onWindowResize();
}
//Function ya lighting
function setLight() {
    //renderer.physicallyCorrectlights = true;
    light = new THREE.AmbientLight(0xffffff)
    scene.add(light);
}


//Hii ni function ya kuload the gltf file yenye iligeneretiwa na blender to our site

function loadGLTF() {
    let droneLoader = new THREE.GLTFLoader(); // hapa tunacreate the GLTFLoader ...Ni kama instances in python , importing the loader
    //load the file  
    droneLoader.load('../Loader/untitled.glb', (gltf) => {
        droneMesh = gltf.scene;
        droneMesh.scale.set(1.5, 1.5, 1.5) //tunaset scale
        scene.add(droneMesh) //tuna add the whole blender scene to the three.js plc 
        // camera = gltf.cameras[0];
        camera.position.copy(gltf.cameras[0].parent.position);
        camera.quaternion.copy(gltf.cameras[0].parent.quaternion);
        camera.scale.copy(gltf.cameras[0].parent.scale);
        /*droneMesh.position.x = -100;
        droneMesh.position.y = 100;
        droneMesh.position.z = -500;*/
    });
}

//Hii ni function ya ku animate. Si lazima itumiwe but kama hautatumia make sure umeposition the 3D model..
//....place unaweza iona kwa screen yako. ie scale it and position it to the centre of your screen

function animate() {
    requestAnimationFrame(animate);

    /*if (droneMesh && droneMesh.rotation) {
      //  droneMesh.rotation.y -= 0.0001;
    }*/

    //droneMesh.rotation.x += 0.01;
    //droneMesh.rotation.y += 0.01;

    renderer.render(scene, camera);
};

init();
setLight();
loadGLTF();
animate();

/*
const geometry = new THREE.BoxGeometry();
const material = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
const cube = new THREE.Mesh(geometry, material);
scene.add(cube);
camera.position.z = 5;




function animate() {
    requestAnimationFrame(animate);

    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;

    renderer.render(scene, camera);
};

animate();*/