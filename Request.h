/**
 * @file Request.h
 * @brief Defines the structure for a single web request.
 * @author Lucas Bryant
 * @date 2025-07-19
 */

 #ifndef REQUEST_H
 #define REQUEST_H
 
 #include <string>
 
 /**
  * @struct Request
  * @brief Holds the data for a single web request.
  *
  * This struct contains all the necessary information to simulate a request,
  * including the source and destination IP addresses and the time needed
  * for a web server to process it.
  */
 struct Request 
 {
     std::string ip_in;      ///< The IP address of the incoming request.
     std::string ip_out;     ///< The IP address the result should be sent to.
     int time_to_process;    ///< The number of clock cycles required to process the request.
 };
 
 #endif // REQUEST_H