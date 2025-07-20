/**
 * @file WebServer.h
 * @brief Defines the WebServer class for processing requests.
 * @author Lucas Bryant
 * @date 2025-07-19
 */

 #ifndef WEBSERVER_H
 #define WEBSERVER_H
 
 #include "Request.h"
 
 /**
  * @class WebServer
  * @brief Simulates a single web server that can process one request at a time.
  *
  * A WebServer instance can be either idle or busy. When busy, it processes a
  * single request, counting down the required clock cycles until completion.
  */
 class WebServer 
 {
     public:
         /**
          * @brief Constructs a new WebServer object.
          *
          * Initializes the server in an idle state with no time remaining on any task.
          */
         WebServer();
 
         /**
          * @brief Checks if the server is currently processing a request.
          * @return true if the server is busy (timeRemaining > 0), false otherwise.
          */
         bool isBusy();
 
         /**
          * @brief Assigns a new request to the server if it is not busy.
          *
          * When a request is taken, the server's state becomes busy, and its
          * timeRemaining is set to the request's processing time.
          * @param req The Request object to be processed.
          */
         void takeRequest(Request req);
 
         /**
          * @brief Simulates one clock cycle of processing for the current request.
          *
          * If the server is busy, it decrements the remaining time. When the time
          * reaches zero, it signifies that the request is finished.
          */
         void process();
 
     private:
         Request curRequest;   ///< The current request being processed by the server.
         int timeRemaining;    ///< The number of clock cycles left to finish the current request.
 };
 
 #endif // WEBSERVER_H