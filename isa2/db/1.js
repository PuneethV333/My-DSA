const { MongoClient } = require('mongodb')
const url = `mongodb://127.0.0.1:27017`;
const client = new MongoClient(url);
const dbName = 'PESU';


const insert = async () => {
    try{
        await client.connect();
        const db = client.db(dbName);
        console.log("connected to db");
        const data = await db.collection('L-section').insertOne({nmae:'Puneeth',branch:'CSE',year:2});
        console.log(data);
    }catch(err){
        console.log(err);
    }finally{
        client.close();
    }
}


const insertmany = async () => {
    try{
        await client.connect();
        console.log('Done ');
        const db = client.db(dbName);
        const data = await db.collection('L-section').insertMany([{}]);
        console.log(data);
    }catch(err){
        console.log(Err);
    }finally{
        client.close();
    }
}



const update = async () => {
    try{
        await client.connect();
        console.log("Connected to db");
        const db = client.db(dbName);
        const data = await db.collection('L-section').updateOne({name:'Puni'},{$set:{name:'Puneeth'}});
        console.log(data);
    }catch(err){
        console.log(err);
    }finally{
        client.close();
    }
}


const updatemany = async () => {
    try{
        await client.connect();
        const db =client.db(dbName);
        console.log("Connected to db");
        const data = await db.collection('L-section').updateMany({},{$set:{branch:"CSE"}});
        console.log(data);
    }catch(err){
        console.log(err);
    }finally{
        client.close();
    }
}


const find = async () => {
    try{
        await client.connect();
        const db = client.db(dbName);
        console.log("Coneected");
        const data = await db.collection('L-Section').find().toArray();
        console.log(data);
    }catch(errr){
        console.error(errr);
    }finally{
        client.close();
    }
}


const del = async () => {
    try{
        await client.connect();
        const db = client.db(dbName);
        console.log(("Connected"));
        const data = await db.collection("L-Section").deleteOne({name:"Puni"});
        console.log(data);
    }catch(err){
        console.log(err);
    }finally{
        client.close()
    }
}


const delMAny = async  () => {
    try{
        await client.connect();
        const db = client.db(dbName);
        console.log('Connected to db');
        const data = await db.collection('L-Section').deleteMany({});
        console.log(data);
    }catch(err){
        console.error(err);
    }finally{
        client.close();
    }
}


const Drop = async () => {
    try{
        await client.connect();
        const db = client.db(dbName);
        console.log("Connected");
        const data = await db.collection('L-Section').drop();
        console.log(data);
    }catch(err){
        console.log(err);
    }finally{
        client.close();
    }
}

