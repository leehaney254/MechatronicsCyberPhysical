const scene = new THREE.Scene(); //creating a scene
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);

const renderer = new THREE.WebGLRenderer(); //creatiing a renderer


let light;
let droneMesh;

//initialization function ya kuset background colour, camera postion na ku render
function init() {
    scene.background = new THREE.Color('grey');
    camera.position.set(0, 10, 20);
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);
}
//Function ya lighting
function setLight() {
    light = new THREE.AmbientLight(0xffffff)
    scene.add(light);
}


//Hii ni function ya kuload the gltf file yenye iligeneretiwa na blender to our site

function loadGLTF() {
    let droneLoader = new THREE.GLTFLoader(); // hapa tunacreate the GLTFLoader ...Ni kama instances in python
    droneLoader.load('./Loader/model.glb', (gltf) => {
        droneMesh = gltf.scene;
        droneMesh.scale.set(25, 25, 25) //tunaset scale
        scene.add(droneMesh) //tuna add scene
        droneMesh.position.x = -5;
        droneMesh.position.y = 5;
        droneMesh.position.z = 5;
    });
}

//Hii ni function ya ku animate. Si lazima itumiwe but kama hautatumia make sure umeposition the 3D model..
//....place unaweza iona kwa screen yako. ie scale it and position it to the centre of your screen

function animate() {
    requestAnimationFrame(animate);

    if (droneMesh && droneMesh.rotation) {
        droneMesh.rotation.y -= 0.01;
    }

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