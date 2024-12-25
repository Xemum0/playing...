import { useEffect } from "react"

function Timer({dispatch ,time}) {
    useEffect(function(){
    const id =   setInterval(() => {
            dispatch({type:"tick"});
        }, 1000);
        return () => clearInterval(id);
    },[dispatch]);
    const min = Math.floor((time/60));
    const sec = time - min*60 ;
  return (
    <div className="timer"> {min}:{sec}</div>
  )
}

export default Timer
