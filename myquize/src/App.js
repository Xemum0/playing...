import { useEffect, useReducer } from "react";
import Header from "./components/Header";
import Loader from "./components/Loader";
import Error from "./components/Error";
import Main from "./components/Main";
import Starter from "./components/Starter";
import Question from "./components/Question";
import NextBtn from "./components/NextBtn";
import Progress from "./components/Progress";
import Finish from "./components/Finish";
import Footer from "./components/Footer";
import Timer from "./components/Timer";

const initialState = {
  questions: [],
  status: "loading",
  index: 0,
  answer: null,
  Score: 0,
  highscore: 0,
  secondRemain:10
};
function reducer(state, action) {
  switch (action.type) {
    case "dataReceived":
      return { ...state, questions: action.payload, status: "ready" };
    case "dataError":
      return { ...state, status: "error" };
    case "active":
      return { ...state, status: "active" };
    case "newAnswer":
      return {
        ...state,
        answer: action.payload.index,
        Score: action.payload.correct
          ? state.Score + action.payload.addition
          : state.Score,
      };
    case "next":
      return { ...state, index: state.index + 1, answer: null };
    case "finished":
      return {
        ...state,
        status: "finished",
        highscore:
          state.highscore < state.Score ? state.Score : state.highscore,
      };
    case "reset":
      return { ...initialState ,highscore : state.highscore,status:"ready", questions:state.questions };
    case "tick":
      return {...state,secondRemain:state.secondRemain-1,status:state.secondRemain <=0 ? "finished":state.status};
    default:
      return state;
  }
}
function App() {
  const [{ status, questions, index, answer, Score, highscore,secondRemain }, dispatch] =
    useReducer(reducer, initialState);
  const numQuestions = questions.length;
  const maxPtn = questions.reduce((prv, cur) => prv + cur.points, 0);
  useEffect(function () {
    fetch("http://localhost:8000/questions")
      .then((res) => res.json())
      .then((data) => dispatch({ type: "dataReceived", payload: data }))
      .catch((err) => dispatch({ type: "dataError" }));
  }, []);

  return (
    <div className="app">
      <Header />
      <Main>
        {status === "error" && <Error />}
        {status === "loading" && <Loader />}
        {status === "ready" && (
          <Starter length={numQuestions} dispatch={dispatch} />
        )}
        {status === "active" && (
          <>
            <Progress
              index={index}
              maxPtn={maxPtn}
              Score={Score}
              numQuestions={numQuestions}
              answer={answer}
            />
            <Question
              question={questions[index]}
              dispatch={dispatch}
              answer={answer}
              Score={Score}
            />
            <Footer>
              <Timer dispatch={dispatch} time={secondRemain} />
              <NextBtn
                dispatch={dispatch}
                answer={answer}
                numQuestions={numQuestions}
                index={index}
              />
            </Footer>
          </>
        )}
        {status === "finished" && (
          <Finish
            maxPtn={maxPtn}
            points={Score}
            high={highscore}
            dispatch={dispatch}
          />
        )}
      </Main>
    </div>
  );
}

export default App;
