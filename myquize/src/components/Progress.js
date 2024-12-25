
function Progress({index,maxPtn,Score,numQuestions,answer}) {
  return (
    <header className="progress">
        <progress max ={numQuestions} value={index + Number(answer!==null)}></progress>
        <p> Question <strong>{index+1}</strong>/ {numQuestions}</p>
        <p> points <strong>{Score}</strong>/{maxPtn}</p>
    </header>
  )
}

export default Progress
