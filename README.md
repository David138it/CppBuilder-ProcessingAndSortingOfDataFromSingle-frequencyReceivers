# CppBuilder-ProcessingAndSortingOfDataFromSingle-frequency receiversSRNS 

<p><strong>Task</strong>:<br />
Create a program in C++ that allows the data received from the receiver from RINEX files in text format to obtain the pseudodality difference (this is the distance between the satellite and the receiver obtained by multiplying the value of the speed of light with the time delay in signal propagation measured by the satellite and receiver clocks) of the satellite and sorts the pseudodalities for each navigation to the satellite to simplify further processing. Here's what the file looks like irkj1380.txt , in which you need to sort the pseudodality for each navigation satellite. We took this data from the base station.<br />
<strong>Task</strong>:<br />
we have sorted the pseudodality data to each satellite for all epochs. zeros in the columns mean that the satellites lack the necessary data. the only thing is, in the lower screenshot we will see that some zeros have appeared and they do not have satellites marked. The fact is that in the program we specified the dimension of the array vector 100 and in each file received from the receiver in our case irkj1380.txt , the number of epochs may be different. Therefore, here it is necessary to adjust the figure 100 in our case. For example, I will put the value here 55. Our table will look more beautiful already. But let's display the data for two satellites
</p>
<p><strong>Manual</strong>:</p>
<ol>
<li>The IDE for C/C++ development - Borland Builder must be installed. I recommend installing the IDE in Windows using the following link: <a href="https://www.youtube.com/watch?v=bDvVosvyVp0&list=LL&index=315" target="_blank">youtube</a></li>
<li>after installation - run Borland Builder - open the project - in the projects tab, click on launch</li>
</ol>
<p><strong>Tools</strong>:</p>
<ol>
<li>Bornald Builder</li>
<ol>
