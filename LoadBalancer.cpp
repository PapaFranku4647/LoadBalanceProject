/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 * @author Lucas Bryant
 * @date 2025-07-19
 */

 #include "LoadBalancer.h"
 #include <iostream>
 #include <cstdlib> 
 #include <ctime>   
 #include <sstream> 
 
 /**
  * @brief Generates a random IPv4 address as a string.
  * @return A string representing a random IP address (e.g., "192.168.1.1").
  */
 std::string generateRandomIp() {
     std::stringstream ss;
     ss << rand() % 256 << "." << rand() % 256 << "." << rand() % 256 << "." << rand() % 256;
     return ss.str();
 }
 
 /**
  * @brief Constructs a new LoadBalancer.
  *
  * Initializes the clock, resizes the web server pool, seeds the random
  * number generator, and populates the initial request queue.
  * @param numberOfServers The initial number of web servers.
  */
 LoadBalancer::LoadBalancer(int numberOfServers) 
 {
     clock = 0;
     if (numberOfServers <= 0) numberOfServers = 1;
     webServers.resize(numberOfServers);
     srand(time(0)); 
     std::cout << "LoadBalancer created with " << numberOfServers << " servers." << std::endl;
     generateInitialRequests(numberOfServers);
     // Rubric requirement: Show the starting queue size.
     std::cout << "Starting queue size: " << requestQueue.size() << " requests." << std::endl;
 }
 
 /**
  * @brief Generates an initial burst of requests.
  *
  * Populates the `requestQueue` with an initial number of requests equal to
  * `numServers` * 100 to simulate a starting load.
  * @param numServers The number of initial servers.
  */
 void LoadBalancer::generateInitialRequests(int numServers) 
 {
     int initialRequests = numServers * 100; 
     
     std::cout << "Generating " << initialRequests << " initial requests..." << std::endl;
     for (int i = 0; i < initialRequests; ++i) {
         Request newReq;
         newReq.ip_in = generateRandomIp();
         newReq.ip_out = generateRandomIp();
         // Task time range for initial requests: 1-50
         newReq.time_to_process = (rand() % 50) + 1; 
         requestQueue.push(newReq);
     }
     std::cout << "Initial request queue populated." << std::endl;
 }
 
 /**
  * @brief Runs the main simulation loop for a specified duration.
  *
  * This method iterates from clock cycle 0 to `totalTime`. In each cycle, it:
  * 1. Potentially adds new random requests to the queue.
  * 2. Scales the number of web servers up or down based on queue size.
  * 3. Assigns requests from the queue to idle servers.
  * 4. Tells each server to process its current request for one cycle.
  * 5. Prints a status update every 100 cycles.
  * @param totalTime The total number of clock cycles for the simulation.
  */
 void LoadBalancer::runSimulation(int totalTime) 
 {
     for (clock = 0; clock < totalTime; ++clock) {
         
         // Randomly add a new request to the queue
         if ((rand() % 20) == 0) { 
              Request newReq;
              newReq.ip_in = generateRandomIp();
              newReq.ip_out = generateRandomIp();
              // Task time range for new random requests: 1-100
              newReq.time_to_process = (rand() % 100) + 1; 
              requestQueue.push(newReq);
         }
 
         // Scale up: Add a new server if the queue is too long
         if (requestQueue.size() > webServers.size() * 10) {
             webServers.push_back(WebServer());
             std::cout << "****** Clock: " << clock << " - High load detected. Adding a new server. Total servers: " 
                       << webServers.size() << " ******" << std::endl;
         }
 
         // Scale down: Remove an idle server if the queue is empty
         if (requestQueue.empty() && webServers.size() > 1) {
             for (size_t i = 0; i < webServers.size(); ++i) {
                 if (!webServers[i].isBusy()) {
                     webServers.erase(webServers.begin() + i);
                     std::cout << "------ Clock: " << clock << " - Low load. Removing idle server. Total servers: "
                               << webServers.size() << " ------" << std::endl;
                     break; 
                 }
             }
         }
 
         // Assign requests from the queue to idle servers
         for (size_t i = 0; i < webServers.size(); ++i) {
             if (!webServers[i].isBusy() && !requestQueue.empty()) {
                 Request reqToProcess = requestQueue.front();
                 requestQueue.pop();
                 webServers[i].takeRequest(reqToProcess);
                 std::cout << "Clock: " << clock << " - Server " << i << " starting request from " 
                           << reqToProcess.ip_in << " for " << reqToProcess.time_to_process << " cycles." << std::endl;
             }
         }
 
         // Tell each server to process for one clock cycle
         for (size_t i = 0; i < webServers.size(); ++i) {
             webServers[i].process();
         }
 
         // Print a status log every 100 cycles
         if (clock % 100 == 0) {
              std::cout << "\n--- Clock: " << clock << ", Requests in queue: " << requestQueue.size() 
                        << ", Active Servers: " << webServers.size() << " ---\n" << std::endl;
         }
     }
 }
 
 /**
  * @brief Prints the final status of the simulation.
  *
  * This function is called once at the end of the simulation to provide
  * a summary that fulfills the project rubric requirements.
  */
 void LoadBalancer::printFinalStatus()
 {
     std::cout << "\n--- End of Simulation Status ---" << std::endl;
     // Rubric requirement: Show the ending queue size.
     std::cout << "Ending queue size: " << requestQueue.size() << " remaining requests." << std::endl;
     
     // Rubric requirement: Show End Status (active/inactive servers)
     int activeServers = 0;
     for(size_t i = 0; i < webServers.size(); ++i) {
         if (webServers[i].isBusy()) {
             activeServers++;
         }
     }
     int inactiveServers = webServers.size() - activeServers;
 
     std::cout << "Final number of servers: " << webServers.size() << std::endl;
     std::cout << "  - Active servers (processing): " << activeServers << std::endl;
     std::cout << "  - Inactive (idle) servers: " << inactiveServers << std::endl;
 
     // Rubric requirement: Show End Status (rejected/discarded requests)
     std::cout << "Rejected / Discarded requests: 0 (All requests are queued)." << std::endl;
     std::cout << "--------------------------------\n" << std::endl;
 }