function Finish({maxPtn,points,high,dispatch}) {
   const percenteg = (points/maxPtn)*100; 
  return (
    <>
     <p className="result">
        you Scored <strong>{points}</strong> out of  {maxPtn}({percenteg}%)
    </p>
    <p className="highscore">(heighscore : {high} points)</p>
    <button className="btn btn-ui" onClick={()=> dispatch({type:"reset"})}>
                restart the game
            </button>
    </>
   
  )
}

export default Finish
