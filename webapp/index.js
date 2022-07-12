const express = require('express');
const User = require('./config');
const path = require('path');
const app = express();
app.use(express.json());


//loading static files
app.set('views', path.join(__dirname, 'static'))

//framework to use in templeting
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, '/views'))

//displaying peagasus
app.get("/", async (req, res) => {
  res.render("peagasus")
})
//getting data from firebase
app.get("/data", async (req, res) => {
  const snapshot = await User.get();
  const list = snapshot.docs.map((doc) => doc.data())
  res.send(list);
})

//after choosing an unkown option
app.get('*', (req, res) => {
  res.send("404 ERROR!!")
})

//where we listen
app.listen(3000, () => {
  console.log("Listening at 3000");
})