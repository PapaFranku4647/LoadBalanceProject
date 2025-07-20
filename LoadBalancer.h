/**
 * @file LoadBalancer.h
 * @brief Defines the LoadBalancer class for managing web servers and requests.
 * @author Lucas Bryant
 * @date 2025-07-19
 */

 #ifndef LOADBALANCER_H
 #define LOADBALANCER_H
 
 #include <vector>
 #include <queue>
 #include "WebServer.h"
 #include "Request.h"
 
 /**
  * @class LoadBalancer
  * @brief Manages a queue of web requests and a pool of web servers.
  *
  * The LoadBalancer distributes incoming requests from a central queue to a
  * dynamic pool of WebServer instances. It also manages the simulation clock
  * and dynamically scales the number of servers up or down based on load.
  */
 class LoadBalancer 
 {
     public:
         /**
          * @brief Constructs a new LoadBalancer object.
          * @param numberOfServers The initial number of web servers to create.
          */
         LoadBalancer(int numberOfServers);
 
         /**
          * @brief Runs the entire load balancing simulation.
          * @param totalTime The total number of clock cycles to run the simulation for.
          */
         void runSimulation(int totalTime);
 
         /**
          * @brief Prints a final summary of the simulation status.
          *
          * This method is called after the simulation finishes to provide a final
          * report including queue size, server status, and other metrics as
          * required by the project rubric.
          */
         void printFinalStatus();
     
     private:
         /**
          * @brief Generates an initial set of requests to populate the queue.
          *
          * Creates a large number of requests (typically 100 times the initial
          * number of servers) to simulate an initial high-load scenario.
          * @param numServers The initial number of servers, used to calculate the queue size.
          */
         void generateInitialRequests(int numServers);
 
         std::queue<Request> requestQueue; ///< The central queue holding all incoming requests.
         std::vector<WebServer> webServers; ///< A dynamic array of active web servers.
         int clock;                         ///< The master clock for the simulation.
 };
 
 #endif // LOADBALANCER_H