// // const express = require("express")
// // const app = express();
// // const expressFileUploader = require('express-fileupload');
// // const fs = require('fs');
// // const path = require('path')
// // app.use(express.json());
// // app.use(express.urlencoded({extended:true}));
// // app.use(expressFileUploader());
// // app.set('view engine','pug');
// // app.set('views',path.join(__dirname,'views'));
// // const uploadDir = path.join(__dirname,'result');
// // if(!fs.existsSync(uploadDir)){
// //     fs.mkdirSync(uploadDir);
// // }


// // app.get('/',(req,res)=>{
// //     res.render('form');
// // })


// // app.post('/',(req,res)=>{
// //     if(!req.files || !req.files.myfile){
// //         return res.send("File not uploaded");
// //     }


// //     const file = req.files.myfile;

// //     file.mv(path.join(__dirname,'/result/',file.name),(err)=>{
// //         if(err){
// //             return res.send(err);
// //         }
// //         res.send('done');
// //     })

// // })


// const express = require('express')
// const app = express();
// const path = require('path')
// const fs = require('fs');
// const fileuploader = require('express-fileupload');
// const uploadDir = path.join(__dirname,'result')
// if(!fs.existsSync(uploadDir)){
//     mkdirSync(uploadDir); 
// }

// app.use(express.json())
// app.use(express.urlencoded({exprended:true}))
// app.use(fileuploader());
// app.set('view engine','pug');
// app.set('views',path.join(__dirname,"views"));

// app.get('/',(req,res)=>{
//     res.render('form');
// })


// app.post('/',(req,res)=>{
//     if(!req.files || !req.files.myfile){
//         return res.send("File not uploaded");
//     }

//     const file = req.files.myfile;
//     file.mv(path.join(__dirname,'/result/',file.name),(err)=>{
//         if(err){
//             return res.send(err);
//         }
//         res.send("Done")
//     });
// })


// app.listen(3000,()=>{
//     console.log("Running");
// })

const http = require('http')
const url = require('url')

const server = http.createServer((req,res)=>{
    res.writeHead(200,{'content-type':'text/html'});
    res.write('<h1>Hellow </h1>')
    var q = url.parse(req.url,true).query;

    res.end(q);
})






















