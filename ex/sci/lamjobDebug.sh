#!/bin/tcsh
# lamjob.pbs 
# sample LAM-MPI PBS script

# DO NOT CHANGE THE ORDER OF THIS FILE.
# DO NOT UNCOMMENT ANYTHING BEGINNING WITH #PBS.
# PBS directives begin with #PBS and
# must preceed all bash statements.
# See man qsub (under EXTENDED DESCRIPTION)
# for more information.

#**************************************
#       User  specifications
#   send email on event (a)bort (b)egin (e)end (n)ever
#PBS -m n
#
#**************************************

#**************************************
#        Job specifications 
#   Queue where we want to run our job.
#   Run 'qstat -a' to see jobs currently running
#   or queue'd.
#PBS -q default

#   Resources reqested from PBS.
#   nodes:    number of nodes allocated to our job.
#             min=1, max=123
#   walltime: walltime before PBS kills our job.
#             min=180, max=96:00:00
#             [[hours:]minutes:]seconds[.milliseconds]
#             Examples:
#               walltime=60      (60 seconds)
#               walltime=10:00   (10 minutes)
#               walltime=5:00:00 (5 hours)
#
#   The command 'qstat -q' will show limits defined for
#   each job queue.
#   See 'man pbs_resources' for a list of other resources
#   which may be requested by a job.
#
#PBS -l nodes=1:1,walltime=10:00:00

#   Our MPI program and arguments
set LAMJOB = "/home/collab/melatti/Eddy_Murphi.3.1/ex/multiset+sym/cache3multi"

#   Number of processes to run per node. [-chk flag?]
set PROCS_PER_NODE = 1

#
#**************************************

#**************************************
#        MPI Start/Run/Shutdown
echo -n "starting to set variables"

set NUM_NODES = `wc -l $PBS_NODEFILE |awk '{print $1}'`
echo -n "NUM_NODES is set"
@ NUM_PROCS = $NUM_NODES * $PROCS_PER_NODE
echo -n "NUM_PROCS is set"

echo -n "Finished setting variables"
#   Save some info to <filename>.pbs.o
echo -n "Job started on "
date
echo "using $NUM_NODES nodes, $PROCS_PER_NODE process(es) per node"
echo -n "master MPI process running on host "
hostname

#   Start up lam
cd $PBS_O_WORKDIR
echo -n "starting "
which lamboot
echo

lamboot 

#   Here is an example of how to use MPI to run a
#   command on each of the nodes.
echo LAM MPI using the following nodes:
lamexec -np $NUM_NODES  hostname

#   MPI runs
echo -n "Starting $LAMJOB using $NUM_PROCS processors using "
which mpirun
echo -n " on "
date
DISPLAY="hanuman.cs.utah.edu:0.1"
mpirun -O -np $NUM_PROCS $LAMJOB >& ${PBS_O_WORKDIR}/output/output.${PBS_JOBID}
echo -n "Finished running job(s) on "
date

#do trace
#lamtrace -v -mpi ${PBS_O_WORKDIR}/myTrace.${PBS_JOBID}


#   Stop lam
echo stopping lam
lamhalt -v
exit

#
#**************************************

