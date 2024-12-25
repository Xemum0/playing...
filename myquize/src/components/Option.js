import React from "react";

function Option({ question, dispatch, answer }) {
  const hasAnswer = answer !== null;
  return (
    <div className="options">
      {question.options.map((option, index) => (
        <button
          key={index}
          className={`btn btn-option ${index === answer ? "answer" : ""} ${
            hasAnswer
              ? index === question.correctOption
                ? "correct"
                : "wrong"
              : ""
          }`}
          onClick={() =>
            dispatch({
              type: "newAnswer",
              payload: {
                index: index,
                correct: index === question.correctOption,
                addition: question.points
              },
            })
          }
          disabled={hasAnswer}
        >
          {option}
        </button>
      ))}
    </div>
  );
}

export default Option;
