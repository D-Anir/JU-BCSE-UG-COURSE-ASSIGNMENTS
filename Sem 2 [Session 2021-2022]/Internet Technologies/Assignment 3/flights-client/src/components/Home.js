import React, { useState, useEffect } from 'react'
import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";
import { Button, List, Row, Col } from "antd";
var moment = require("moment");

const Home = () => {
    const [offers, setOffers] = useState([]);
    useEffect(() => {
      fetch("http://localhost:8080/Travel_Thru_Air/getFlightDetails")
        .then((response) => response.json())
        .then((data) => {
          console.log(data);
          setOffers(
            data.filter((offer) => {
              let time = new Date();
              time.setHours(offer.time, 0, 0);
              let curr_time = new Date();
              // curr_time.setHours(1, 0, 0);
              return time >= curr_time;
            })
          );
        })
        .catch((error) => console.log(error, "ERROR!"));
    }, []);
    return (
      <div>
        <div
          style={{
            backgroundColor: "#242a3e",
            color: "white",
            padding: "2%",
            fontSize: "24px",
            boxShadow: "0 16px 18px 0 rgba(0, 0, 0, 0.16)",
            textAlign: 'center'
          }}
        >
          <h2>Travel Thru Air</h2>
        </div>
        <div style={{ margin: "40px" }}>
          <h1>Special Offers Today!</h1>
        </div>
        <List itemLayout="vertical" size="large">
          {offers.map((offer, idx) => {
            let time = new Date();
            time.setHours(offer.time, 0, 0);
            return (
              <List.Item
                key={idx}
                style={{
                  marginLeft: "100px",
                  marginRight: "100px",
  
                  padding: "30px",
                }}
              >
                <Row
                  style={{
                    marginBottom: "1%",
                    padding: "1%",
                    paddingLeft: "2%",
                    paddingRight: "2%",
                    paddingBottom: "50px",
                    border: "3px solid #e3e3e3",
                    borderRadius: "20px",
                    boxShadow: "0 12px 14px 0 rgba(0, 0, 0, 0.1)",
                  }}
                >
                  <span
                    style={{
                      width: "300px",
                      marginLeft: "20px",
                      marginTop: "60px",
                      fontSize: "24px",
                    }}
                  >
                    <img
                      alt="logo"
                      width="75px"
                      height="75px"
                      style={{ borderRadius: "70px" }}
                      src={offer.image_url}
                    ></img>
                  </span>
                  <span
                    style={{
                      width: "300px",
                      margin: "20px",
                      marginTop: "-25px",
                      fontSize: "24px",
                    }}
                  >
                    {offer.name}
                  </span>
                  <span
                    style={{ width: "300px", margin: "20px", fontSize: "24px" }}
                  >
                    {offer.source}
                  </span>
                  <span
                    style={{
                      width: "300px",
                      margin: "20px",
                      fontSize: "24px",
                      color: "#697b8c",
                    }}
                  >
                    TO
                  </span>
                  <span
                    style={{ width: "300px", margin: "20px", fontSize: "24px" }}
                  >
                    {offer.destination}
                  </span>
                  <span
                    style={{ width: "300px", margin: "20px", fontSize: "24px" }}
                  >
                    INR <s style={{ color: "#697b8c" }}>{offer.cost}</s>
                    {offer.reduced_cost}
                  </span>
                  <span
                    style={{ width: "300px", margin: "20px", fontSize: "24px" }}
                  >
                    Buy 2 or more tickets to avail this offer
                  </span>
                  <span
                    style={{ width: "300px", margin: "20px", fontSize: "24px", color:'red'}}
                  >
                    Valid till : {moment(new Date(time)).format("hh:mm A")}
                  </span>
                </Row>
              </List.Item>
            );
          })}
        </List>
  
        <div style={{ padding: "15%", paddingTop: "3%", fontSize: "20px" }}>
          <Button
            style={{
              float: "right",
  
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
            <Link to="bookFlights">Book Flight</Link>
          </Button>
        </div>
      </div>
    );
}

export default Home