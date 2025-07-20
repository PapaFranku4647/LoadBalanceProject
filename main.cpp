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
 
     std::cout << "--- Load Balancer Simulation Setup ---" << std::endl;
     std::cout << "Enter the initial number of web servers: ";
     std::cin >> numServers;
 
     std::cout << "Enter the total simulation time (in clock cycles): ";
     std::cin >> simulationTime;
     std::cout << "--------------------------------------\n" << std::endl;
 
     // Create a LoadBalancer instance with the user-specified number of servers
     LoadBalancer myLoadBalancer(numServers); 
   
     // Run the simulation for the specified duration
     myLoadBalancer.runSimulation(simulationTime);
 
     std::cout << "\nSimulation finished." << std::endl;
     
     // Print the final status report as required by the rubric
     myLoadBalancer.printFinalStatus();
     
     return 0;
 }