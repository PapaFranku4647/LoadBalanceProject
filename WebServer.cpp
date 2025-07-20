/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class.
 * @author Lucas Bryant
 * @date 2025-07-19
 */

 #include "WebServer.h"
 #include <iostream>
 
 /**
  * @brief Constructs a new WebServer object.
  *
  * The server is initialized with `timeRemaining` set to 0, indicating it is idle.
  */
 WebServer::WebServer() 
 {
     timeRemaining = 0;
 }
 
 /**
  * @brief Checks if the server is busy.
  * @return True if `timeRemaining` is greater than 0, otherwise false.
  */
 bool WebServer::isBusy() 
 {
     return timeRemaining > 0;
 }
 
 /**
  * @brief Assigns a request to the server.
  *
  * If the server is not currently busy, it takes the new request `req` and
  * sets `timeRemaining` to the time required to process that request.
  * @param req The request to be processed.
  */
 void WebServer::takeRequest(Request req) 
 {
     if (!isBusy()) {
         curRequest = req;
         timeRemaining = req.time_to_process;
     }
 }
 
 /**
  * @brief Processes the current request for one clock cycle.
  *
  * If the server is busy, `timeRemaining` is decremented. If `timeRemaining`
  * becomes 0, a message is printed indicating the request is finished.
  */
 void WebServer::process() 
 {
     if (isBusy()) {
         timeRemaining--;
         if (timeRemaining == 0) {
             std::cout << "          Server finished request from " << curRequest.ip_in << std::endl;
         }
     }
 }