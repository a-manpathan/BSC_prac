const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const bodyParser = require('body-parser');
const listRoutes = require('./routes/listRoutes');

const app = express();

app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

mongoose.connect('mongodb://127.0.0.1:27017/todolist')
    .then(() => { console.log('Successfully connected to the database') });

app.use(listRoutes);

app.listen(3000, () => {
    console.log('server is running on port 3000');
});