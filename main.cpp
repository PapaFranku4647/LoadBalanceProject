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
     int numServers;
     int simulationTime;
 
     // Get simulation parameters from the user
     std::cout << "Enter the number of web servers to simulate: ";
     std::cin >> numServers;
 
     std::cout << "Enter the total time (in clock cycles) to run the simulation: ";
     std::cin >> simulationTime;
 
     std::cout << "Starting simulation with " << numServers << " servers for "
               << simulationTime << " clock cycles." << std::endl;
 
     // Create a LoadBalancer instance with the specified number of servers
     LoadBalancer myLoadBalancer(numServers); 
   
     // Run the simulation for the specified duration
     myLoadBalancer.runSimulation(simulationTime);
 
     std::cout << "Simulation finished." << std::endl;
     
     return 0;
 }