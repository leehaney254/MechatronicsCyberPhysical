//configurations
const firebase = require('firebase')

const firebaseConfig = {
  apiKey: "AIzaSyBfbMjSGBq-YYgwFG7OVe9g94aXpvRGKZw",
  authDomain: "pegasus-3b383.firebaseapp.com",
  projectId: "pegasus-3b383",
  storageBucket: "pegasus-3b383.appspot.com",
  messagingSenderId: "396066997907",
  appId: "1:396066997907:web:221054fa44e21999b02f66"
};

// Get a database reference to our posts
firebase.initializeApp(firebaseConfig);
const ref = firebase.database().ref("Sensor");


//requirements
const express = require('express');
const path = require('path');
const app = express();
app.use(express.json());
app.use(express.static(path.join(__dirname, '/static')))


//framework to use in templeting
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, '/views'))

//displaying peagasus
app.get("/", async (req, res) => {
  res.render("peagasus")
})
//getting data from firebase
// Attach an asynchronous callback to read the data at our posts reference
app.get("/data", async (req, res) => {
  ref.on('value', (snapshot) => {
    let data = snapshot.val();
    res.render("data", { data: data });
  }, (errorObject) => {
    console.log('The read failed: ' + errorObject.name);
  });
})


//go to team views
app.get("/team", async (req, res) => {
  res.render("team")
})
//after choosing an unkown option
app.get('*', (req, res) => {
  res.send("404 ERROR!!")
})

//where we listen
app.listen(3000, () => {
  console.log("Listening at 3000");
})