import React from 'react'

export default function Starter({length , dispatch}) {
  return (
    <div className='start'>
      <h3>welcome to the quize {length} of questions </h3>
      <button className='btn btn-ui' onClick={() => dispatch({type:"active"})}>lets Start</button>
    </div>
  )
}
