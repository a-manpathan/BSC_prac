const express = require('express');
const routes = express.Router();
const List = require('../schema/listschema');

routes.get('/list-items', async (req, res) => {
    try {
        const response = await List.find();
        res.send(response);
    }
    catch (err) {
        throw err;
    }

});

routes.post('/list-items', (req, res) => {

    const list = new List({
        todo: req.body.todo
    });
    list.save();
    res.status(200).send();
});

routes.delete('/list-items/:id', async (req, res) => {
    const id = req.params.id;
    await List.findByIdAndDelete(id);
    res.status(200).send();
});

module.exports = routes;