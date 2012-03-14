var express = require('express')
 , app = express.createServer()
 , io = require('socket.io').listen(app);

app.use(express.bodyParser());
app.use('/static', express.static( __dirname + '/static'));
app.listen(8888);

var currentSocket;

app.get('/', function (req, res) {
  console.log("Get request recieved");
  res.sendfile(__dirname + '/index.html');
});

app.post('/update', function(req, res) {
	console.log("Post request recieved!");
	for (var key in req.body)
	{
		var accelerometerData = key;
		console.log(key);
		currentSocket.emit('acceleromessage', accelerometerData);
		break;
	}
});

io.sockets.on('connection', function (socket) {
  currentSocket = socket;
  socket.emit('message', 'First message from server');
});
