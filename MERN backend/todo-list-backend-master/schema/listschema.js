const mongoose = require('mongoose');
const listSchema = mongoose.Schema({
    todo: {
        type: String,
        required: true
    }
});

const List = mongoose.model("Item", listSchema);

module.exports = List;