const val = require('validator')
console.log(val.isEmail('mamathapreetham817@gmail.com'));


const http = require('http');

const server = http.createServer((req,res)=> {
    res.writeHead(200,{'content-type':'text/html'});
    res.write('<h1>Hello world</h1>');
    res.end();
});

server.listen(3000);



const http = require('http');
const url = require('url');

const server = http.createServer((req,res)=>{
    res.writeHead(200,{'content-type':'text/html'});
    var q = url.parse(req.url,true).query;
    var texr = q.data+""+q.month;
    res.end(texr);
});



server.listen(3000); 





const buf = Buffer.alloc(10);
buf.write("hello");
const buf1 = Buffer.from('Hello world');
const buf2 = Buffer.from('hi');

console.log(buf1);
console.log(buf2);

const newBuffer = Buffer.concat([buf1,buf2]);
console.log(newBuffer);

var buf3 = Buffer.from("nice");
var buf4 = Buffer.from("naa");

buf3.copy(buf4);


console.log(Buffer.compare(buf3,buf4));



const fs = require('fs');
var data = "";
const readStream = fs.createReadStream('test.text','utf-8');

readStream.on('data',(i)=>{data+= i});
readStream.on('end',()=>{console.log(data)});
readStream.on('error',()=>{console.log(err)});


const writeStram = fs.createWriteStream('test.txt','utf-8');
writeStram.write(data)
writeStram.on('finish',()=>{
    console.log("Done writing");
})
writeStram.on("error",(err)=>{
    console.error(err);
})



readStream.pipe(writeStram);





fs.writeFile('test.txt',"hello World",(err)=>{
    if(err){
        console.log(err);
    }else{
        console.log("done");
    }
})


fs.readFile('new.txt','utf-8',(err,data)=>{
    if(err){
        console.log(err);      
    }else{
        console.log(data);
    }
});

fs.appendFile('new.txt','nkn lee',()=>{
    console.log("done");
})


const express = require('express');
const app = express();

app.get('/',(req,res)=>{
    res.send('Done');
})

app.get('/:id',(req,res)=>{
    res.send(req.params.id);
})

app.listen(3000);



const express = require(express);
const app = express();

app.use((req,res,next)=>{
    console.log('middleware-1');
    next();
})


app.use((err,req,res,next)=>{
    console.log(err);
    res.send('Something broke');
})




app.get('/',(req,res,next)=>{
    console.log('middlewere-2');
    next();
})

app.get('/',(req,res)=>{
    console.log('middlewere-3');
    res.send('Hello');
})


const express = require('express');
const app = express();
const path = require('path')
app.use(express.urlencoded({extended:true}));
app.use(express.json())

app.set('view engine','pug');
app.set('views',path.join(__dirname,'views'));

app.get('/',(req,res)=>{
    res.render('form');
})

app.post('/',(req,res)=>{
    console.log("done");
    res.render('res',req.body);
})






const express = require("express");
const app = express();
const path = require('path');
app.use(express.json());
app.use(express.urlencoded({extended:true}));
const fs = require('fs')
const fileUpload = require('express-fileupload')
app.use(fileUpload());
app.set('view engine','pug');
app.set('views',path.join(__dirname,'views'));
const updoadDir = path.join(__dirname,'result');
if(!fs.existsSync(updoadDir)) {
    fs.mkdirSync(updoadDir)
}
app.get('/',(req,res)=>{
    res.render('fileForm');
})


app.post('/',(req,res)=>{
    if(!req.files || !req.files.myfile ){
        return res.send("file not found");
    }

    let file = req.files.myfile;

    file.mv(path.join(__dirname,'/result/',file.name),(err)=>{
        if(err){
            return res.send(err);
        }
        res.send('done job');
    })
})


