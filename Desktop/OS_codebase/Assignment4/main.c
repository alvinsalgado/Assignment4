#include<stdio.h>

int main()
{

     // Set arrays to a given size
     int Maximum[20], Total[20], resoNeed[20],

          sequence[20], avilable, job, loop, loop1 = 0, delim, max, needed, exec;

     // Ask user to enter number of processes
     printf("Enter number of processes: ");
     scanf("%d", &needed);

     // for() loop used to enter all the resources required by the processes
    for (loop = 0; loop<needed; loop++)
     {
          printf("Enter maximum resources for process %d are : ", loop);
          scanf("%d", &Maximum[loop]);

          printf("\nEnter the allocated resources for process %d are : ", loop);
          scanf("%d", &Total[loop]);

          // Used to check the needed resources
          resoNeed[loop] = Maximum[loop] - Total[loop];

          printf("\nThe total needed resources %d are : %d", loop, resoNeed[loop]);

     }

     // Ask user to enter the available resources
     printf("\nEnter the available resources : ");
     scanf("%d", &avilable);

     // Print the maximum, allocation, and needed
     printf("\nmax      allocation      needed \n");

     // for() loop used to print the values of max, allocation and needed
     for (loop = 0; loop<needed; loop++)

     {
          printf("%d        %d                  %d", Maximum[loop], Total[loop], resoNeed[loop]);
          printf("\n");
     }

     max = delim = needed;

     exec = max + 1;

     // while() loop used to check if the state of the system is in safe state or unsafe state
     while (max>0)
     {
          if (delim == exec)

              max = 0;

          else
          {
              delim = exec;

              exec = 0;

              // for() loop used to calculate required resources
              for (loop = 0; loop<needed; loop++)

                   if ((resoNeed[loop]>0) && (resoNeed[loop] <= avilable))
                   {
                        resoNeed[loop] = 0;

                        job = Total[loop] + avilable;

                        avilable = job;

                        sequence[loop1] = loop;

                        max--;

                        loop1++;
                   }
                   else
                        exec++;

          }

     }

     // if() used to check if safe state or unsafe state.
     // then print safe state or unsafe state
     if (delim == exec)

          printf("\n This sequence is unsafe");

     else
     {

          printf("\n This sequence is safe");

          printf("\nThe process have the following sequence:");

          // use for() loop to print the sequences of processes
          for (loop = 0; loop<needed; loop++)

              printf(" %d\t", sequence[loop]);

     }

     return 0;

}
