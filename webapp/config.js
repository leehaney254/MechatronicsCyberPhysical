const firebase = require('firebase');

const firebaseConfig = {
  apiKey: "AIzaSyCgPv0Ib6R0wm8PwOmpCEzsG2c5NIk730I",
  authDomain: "fir-20fd7.firebaseapp.com",
  databaseURL: "https://fir-20fd7-default-rtdb.firebaseio.com",
  projectId: "fir-20fd7",
  storageBucket: "fir-20fd7.appspot.com",
  messagingSenderId: "332813658093",
  appId: "1:332813658093:web:f11669190b03ce4a14e9e4",
  measurementId: "G-L3EDMWD7R6"
};

firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();
const User = db.collection("Users")
module.exports = User;