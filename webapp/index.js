//configurations
const firebase = require('firebase')

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBWb-pPO-mxbiT7Ha7DIYhYlpDqtBFyhjg",
  authDomain: "testing-58bc5.firebaseapp.com",
  databaseURL: "https://testing-58bc5-default-rtdb.firebaseio.com",
  projectId: "testing-58bc5",
  storageBucket: "testing-58bc5.appspot.com",
  messagingSenderId: "816235286882",
  appId: "1:816235286882:web:f54dff143119a578621c3b"
};

// Get a database reference to our posts
firebase.initializeApp(firebaseConfig);
const ref = firebase.database().ref("Sensor");


//requirements
const express = require('express');
const path = require('path');
const app = express();
let data;
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
ref.on('value', (snapshot) => {
  data = snapshot.val();
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});
app.get("/data", async (req, res) => {
  res.render("data", { data: data });
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