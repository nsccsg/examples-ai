/* Sample program: sample1.c                                        */
/* Copyright (C) 2003, Fujitsu Limited, All Rights Reserved.        */
/* $Id: sample1.c,v 1.1 2003/10/09 22:25:04 matsu Exp $ */

#include <stdio.h>
#include "mpi.h"

int	
main(int argc, char *argv[])
{
	int  rank, size;
	int  namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Get_processor_name(processor_name,&namelen);
	fprintf(stdout,"%2d:%s\n",rank, processor_name);
	MPI_Finalize();
	return 0;
}
