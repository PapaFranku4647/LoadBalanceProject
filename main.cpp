/**
 * @file main.cpp
 * @brief The driver program for the Load Balancer simulation.
 * @author Lucas Bryant
 * @date 2025-07-19
 *
 * This program serves as the entry point for the simulation. It prompts the
 * user for the initial number of servers and the total simulation duration,
 * then creates and runs a LoadBalancer instance.
 */

 #include <iostream>
 #include "LoadBalancer.h" 
 
 /**
  * @brief The main function, entry point of the program.
  * 
  * Prompts the user to enter the initial number of web servers and the
  * total simulation time in clock cycles. It then instantiates and runs
  * the LoadBalancer simulation with the provided parameters.
  *
  * @return int Returns 0 upon successful execution.
  */
 int main() {
     // Hardcoded values for log generation as per assignment requirements
     int numServers = 10;
     int simulationTime = 10000;
 
     std::cout << "--- Simulation Configuration ---" << std::endl;
     std::cout << "Initial number of servers: " << numServers << std::endl;
     std::cout << "Total simulation time: " << simulationTime << " clock cycles." << std::endl;
     std::cout << "Initial request task time range: 1 to 50 cycles." << std::endl;
     std::cout << "Random new request task time range: 1 to 100 cycles." << std::endl;
     std::cout << "--------------------------------\n" << std::endl;
 
     std::cout << "Starting simulation..." << std::endl;
 
     // Create a LoadBalancer instance with the specified number of servers
     LoadBalancer myLoadBalancer(numServers); 
   
     // Run the simulation for the specified duration
     myLoadBalancer.runSimulation(simulationTime);
 
     std::cout << "\nSimulation finished." << std::endl;
     
     // Print the final status report as required by the rubric
     myLoadBalancer.printFinalStatus();
     
     return 0;
 }