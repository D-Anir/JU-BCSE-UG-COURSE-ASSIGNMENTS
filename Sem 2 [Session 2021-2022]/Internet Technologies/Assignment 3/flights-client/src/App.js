import React from "react";
import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";
import Home from "./components/Home";
import BookFlights from "./components/BookFlights";

export default function App() {
  return (
    <Router>
      <Switch>
        <Route path="/bookFlights">
          <BookFlights />
        </Route>
        <Route path="/">
          <Home />
        </Route>
      </Switch>
    </Router>
  );
}

