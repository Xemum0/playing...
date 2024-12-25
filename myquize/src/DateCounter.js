import { useReducer } from "react";

const initiatStat = { count: 0, step: 1 };
function reducer(state, action) {
  switch (action.act) {
    case "dec":
      return { ...state, count: state.count - state.step };
    case "inc":
      return { ...state, count: state.count + state.step };
    case "def":
      return { ...state, count: action.payload };
    case "step":
      return {...state,step:action.payload};
    case "reset":
      return initiatStat;
    default:
      return state;
  }
}

function DateCounter() {
  const [state, dispatch] = useReducer(reducer, initiatStat);
  const { count, step } = state;
  // This mutates the date object.
  const date = new Date("june 21 2027");
  date.setDate(date.getDate() + count);

  const dec = function () {
    dispatch({ act: "dec"});
  };

  const inc = function () {
    dispatch({ act: "inc"});
  };

  const defineCount = function (e) {
    dispatch({ act: "def", payload: Number(e.target.value) });
  };

  const defineStep = function (e) {
    dispatch({ act: "step", payload: Number(e.target.value) });
  };

  const reset = function () {
    dispatch({ act: "reset"});
  };

  return (
    <div className="counter">
      <div>
        <input
          type="range"
          min="0"
          max="10"
          value={step}
          onChange={defineStep}
        />
        <span>{step}</span>
      </div>

      <div>
        <button onClick={dec}>-</button>
        <input value={count} onChange={defineCount} />
        <button onClick={inc}>+</button>
      </div>

      <p>{date.toDateString()}</p>

      <div>
        <button onClick={reset}>Reset</button>
      </div>
    </div>
  );
}
export default DateCounter;
