const firebase = require('firebase');

const firebaseConfig = {
  apiKey: "AIzaSyBfbMjSGBq-YYgwFG7OVe9g94aXpvRGKZw",
  authDomain: "pegasus-3b383.firebaseapp.com",
  projectId: "pegasus-3b383",
  storageBucket: "pegasus-3b383.appspot.com",
  messagingSenderId: "396066997907",
  appId: "1:396066997907:web:221054fa44e21999b02f66"
};

firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();
const User = db.collection("Users")
module.exports = User;