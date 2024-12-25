import { useEffect } from "react"

function Timer({dispatch ,time}) {
    useEffect(function(){
    const id =   setInterval(() => {
            dispatch({type:"tick"});
        }, 1000);
        return () => clearInterval(id);
    },[dispatch]);
  return (
    <div className="timer"> {time}</div>
  )
}

export default Timer
