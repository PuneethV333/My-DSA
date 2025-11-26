import React, {  useState } from "react";
import { createRoot } from "react-dom/client";

const Im = ({ src }) => {
  return <img src={src} />;
};

const Txt = ({ text }) => {
  return <h1>{text}</h1>;
};

const Res = () => {
  return (
    <div>
      <Im src="https://www.google.com/imgres?q=xor&imgurl=https%3A%2F%2Fwww.allaboutcircuits.com%2Fuploads%2Farticles%2FXOR-gate-circuit-calculation.jpg&imgrefurl=https%3A%2F%2Fwww.allaboutcircuits.com%2Ftextbook%2Fdigital%2Fchpt-7%2Fthe-exclusive-or-function-xor%2F&docid=uzCzP4Q2hfMIyM&tbnid=U0PVHBpNJs673M&vet=12ahUKEwjGhNDotIaRAxX6TWwGHeNcCFwQM3oECBIQAA..i&w=443&h=380&hcb=2&ved=2ahUKEwjGhNDotIaRAxX6TWwGHeNcCFwQM3oECBIQAA" />
      <Txt text="Image" />
    </div>
  );
};

const Result = () => {
  return (
    <div>
      <Res />
    </div>
  );
};

const Key = () => {
  const i = ["apple", "banana", "noo"];
  return (
    <ul>
      {i.map((k, idx) => (
        <li key={idx}>{k}</li>
      ))}
    </ul>
  );
};

const Print = () => {
  const click = () => {
    console.log("clicked");
  };
  return <button onClick={click}>Click</button>;
};

import { useState } from "react";

const Counter = () => {
  const [count, setCount] = useState(0);
  return (
    <div>
      <h2>{count}</h2>
      <button
        onClick={() => {
          setCount(count + 1);
        }}
      >
        {" "}
        +{" "}
      </button>
      <button
        onClick={() => {
          setCount(count - 1);
        }}
      >
        {" "}
        -{" "}
      </button>
      <button
        onClick={() => {
          setCount(0);
        }}
      >
        reset
      </button>
    </div>
  );
};


import { useEffect,useState } from "react";


const Res2 = () => {
  const [count,setCount] = useState(0);
  useEffect(()=>{
    console.log(count);
  },[count]);

  return(
    <div>
      <h1>{count}</h1>
      <button onClick={() => {setCount(count+1)}}>+</button>
      <button onClick={() => {setCount(count-1)}}> - </button>
    </div>
  )
}



import { useState,useRef,useEffect } from "react";


const res3 = () => {
  const [count,setCount] = useState(0);
  const prevCount = useRef(0);

  useEffect(() => {
    prevCount.current = count;
  },[count]);




  return(
    <div>
      <h1>{count}</h1>
      <h2>PrevCount: {prevCount}</h2>
      <button onClick={() => {setCount(count+1)}}> + </button>
      <button onClick={() => {setCount(count-1)}}> - </button>
      <button onClick={() => {setCount(0)}}> reset </button>
    </div>
  )
}







import { useState,createContext,useContext } from "react";

const myContext = createContext();



const Res4 = () => {
  const [theme,setTheme] = useState('light') 
  return(
    <myContext.Provider value={{theme,setTheme}}>
      <Btn2/>
    </myContext.Provider>
  )
}


const Btn2 = () => {
  const {theme,setTheme} = useContext(myContext);
  const toogleState = () => {
    theme == 'light'? setTheme('dark'):setTheme('light')
  }
  
  return(
    <div>
      <button onClick={toogleState}>toggle</button>
      <h1>theme:{theme}</h1>
    </div>
  )
}





import {useReducer} from 'react'



const reduce = (state,action) => {
  switch(action.type){
    case 'INC':
      return {count:state.count+1}
    case 'DEC':
      return {count:state.count -1}
    case 'RESET':
      return {count:0}
    default:
      return state;
  }
}


const count45 = () => {
  const initState = {count:0};
  const [state,dispatch] = useReducer(reduce,initState)
  return(
    <div>
      <h2>{state.count}</h2>

      <button onClick={() => {dispatch({type:'INC'})}}>+</button>
      <button onClick={() => {dispatch({type:'DEC'})}}>-</button>
      <button onClick={() => {dispatch({type:'RESET'})}}>reset</button>
    </div>
  )
}

import {Link,Routes,Route,BrowserRouter} from 'react-router-dom'



const App = () => {
  return(
    <BrowserRouter>
      <div>
          <Link to='\home'>Home</Link>
          <Link to='\about'>About</Link>
          <Link to='\contact'>Contact</Link>
      
      <Routes>
          <Route path="/" element={<Res/>} />
          <Route path="/home" element={<Res4/>}/>
          <Route path="/home" element={<Res2/>}/>

          </Routes>
          </div>
    </BrowserRouter>
  )
}




createRoot(document.getElementById("root")).render(<App />);
// createRoot(document.getElementById("root")).render(<Btn2 />);
// createRoot(document.getElementById("root")).render(<Key />);
