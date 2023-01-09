import React, { useState, useEffect } from 'react'
import { Button, List, Row, Col } from "antd";
import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";
var moment = require("moment");

const BookFlights = () => {
    const [source, setSource] = useState("");
    const [dest, setDest] = useState("");
    const [time, setTime] = useState("");
    const [flights, setFlights] = useState([]);
    const onChangeSource = (e) => {
      setSource(e.target.value);
    };
    const onChangeDest = (e) => {
      setDest(e.target.value);
    };
    const onChangeTime = (e) => {
      setTime(e.target.value);
    };
    const handleSubmit = (e) => {
      console.log("inside handle submit")
      let x = parseInt(time.substr(0, 2)).toString();
      e.preventDefault();
      fetch(
        `http://localhost:8080/Travel_Thru_Air/showFlightDetails?source=${source}&destination=${dest}&time=${x}`,{
          mode: 'no-cors'
        }
      )
        .then((response) => {
          console.log(response);
          return response.json();
        })
        .then((data) => {
          console.log(data);
          setFlights(data);
        })
        .catch((error) => console.log(error));
    };
  
    return (
      <React.Fragment>
        <div
          style={{
            backgroundColor: "#242a3e",
            color: "white",
            padding: "2%",
            fontSize: "24px",
            boxShadow: "0 16px 18px 0 rgba(0, 0, 0, 0.16)",
            textAlign: 'center',
          }}
        >
          <h2>Travel Thru Air</h2>
        </div>
  
        <div
          style={{
            padding: "15%",
            paddingTop: "3%",
            paddingBottom: "3%",
            fontSize: "20px",
            justifyContent: 'center',
            alignItems: 'center'
          }}
        >
          <form onSubmit={handleSubmit}>
            <span style={{ margin: "2%", fontSize: "20px" }}>
              <labeL>Enter Source: </labeL>
              <input
                style={{ width: "150px", height: "28px", fontSize: "20px" }}
                type="text"
                name="source"
                value={source}
                onChange={onChangeSource}
              />
            </span>
            <span style={{ margin: "2%", fontSize: "20px" }}>
              <labeL>Enter Destination: </labeL>
              <input
                style={{ width: "150px", height: "28px", fontSize: "20px" }}
                type="text"
                name="destination"
                value={dest}
                onChange={onChangeDest}
              />
            </span>
            <span style={{ margin: "2%", fontSize: "20px" }}>
              <labeL>Enter Flight Time: </labeL>
              <input
                style={{ width: "150px", height: "28px", fontSize: "20px" }}
                type="text"
                name="time"
                value={time}
                onChange={onChangeTime}
              />
            </span>
            <span style={{ margin: "2%" }}>
              <input
                style={{
                  width: "150px",
                  height: "50px",
                  fontSize: "20px",
                  borderRadius: "10px",
                  backgroundColor: "#242a3e",
                  color: "white",
                }}
                type="submit"
                value="Search"
              ></input>
            </span>
          </form>
        </div>
        {/* <div
          style={{
            margin: "30px",
            padding: "30px",
            display: "flex",
          }}
        >
          <span style={{ width: "300px", margin: "20px", fontSize: "20px" }}>
            SOURCE
          </span>
          <span style={{ width: "300px", margin: "20px", fontSize: "20px" }}>
            DESTINATION
          </span>
          <span style={{ width: "300px", margin: "20px", fontSize: "20px" }}>
            PRICE
          </span>
          <span style={{ width: "300px", margin: "20px", fontSize: "20px" }}>
            DEPARTURE TIME
          </span>
          <span style={{ width: "300px", margin: "20px", fontSize: "20px" }}>
            LEGS
          </span>
        </div> */}
        <List itemLayout="vertical" size="large">
          {flights.map((offer, idx) => {
            let time = new Date();
            time.setHours(offer.time, 0, 0);
            return (
              <List.Item
                key={idx}
                style={{
                  marginLeft: "100px",
                  marginRight: "100px",
  
                  padding: "30px",
                  // background: "cyan",
                }}
              >
                <Row
                  style={{
                    marginBottom: "1%",
                    padding: "1%",
                    paddingLeft: "3%",
                    paddingRight: "3%",
                    border: "3px solid #e3e3e3",
                    borderRadius: "20px",
                    boxShadow: "0 12px 14px 0 rgba(0, 0, 0, 0.1)",
                  }}
                >
                  <Col
                    style={{
                      marginTop: "10px",
                      fontSize: "28px",
                      width: "200px",
                    }}
                  >
                    <img
                      alt="logo"
                      width="75px"
                      height="75px"
                      float="left"
                      style={{ borderRadius: "70px" }}
                      src={offer.image_url}
                    />
                    <p style={{ marginLeft: "100px", marginTop: "-60px" }}>
                      {offer.name}
                    </p>
                  </Col>
  
                  <Col
                    style={{
                      width: "700px",
                      marginLeft: "360px",
                      marginTop: "-100px",
                      border: "2px solid white",
                      fontSize: "20px",
                    }}
                  >
                    <div
                      style={{
                        float: "right",
                        marginRight: "-380px",
                      }}
                    >
                      Price: INR {offer.price}
                    </div>
                    {offer.dest.map((d, i) => (
                      <>
                        <div style={{ fontSize: "22px", marginTop: "35px" }}>
                          <span>{offer.src_time[i]}</span>
                          <span
                            style={{
                              position: "absolute",
                              right: "900px",
                              //marginLeft: "340px",
                              color: "#697b8c",
                              fontSize: "20px",
                              fontWeight: "900",
                            }}
                          >
                            LEG {i + 1}
                          </span>
                          <span style={{ float: "right" }}>
                            {offer.dest_time[i]}
                          </span>
                        </div>
                        <div
                          style={{
                            color: "#697b8c",
                            marginTop: "4px",
                            marginBottom: "35px",
                          }}
                        >
                          <span>{offer.src[i]}</span>
                          <span style={{ float: "right" }}>{offer.dest[i]}</span>
                        </div>
                        {i !== offer.dest.length - 1 && (
                          <hr style={{ color: "#697b8c", width: "100%" }} />
                        )}
                      </>
                    ))}
                  </Col>
  
                  <Col style={{}}>
                    <Button
                      style={{
                        float: "right",
                        marginTop: "-80px",
                        cursor: "pointer",
                        fontSize: "18px",
                        fontWeight: "900",
                        borderRadius: "4px",
                        textAlign: "center",
                        width: "151px",
                        height: "78px",
                        padding: "5px 2px",
                        color: "white",
                        border: "solid 1.5px #319c7f",
                        backgroundColor: "#319c7f",
                      }}
                    >
                      {"SELECT"}
                    </Button>
                  </Col>
                </Row>
              </List.Item>
            );
          })}
        </List>
      </React.Fragment>
    );
}

export default BookFlights