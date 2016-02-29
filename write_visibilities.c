/*
 * Copyright (c) 2015-2016 Marzia Rivi, Ian Harrison
 *
 * This file is part of RadioLensfit.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "read_coordinates.h"

 #ifdef __cplusplus
extern "C" {
#endif

//num_vis  = num_channels * num_times * num_baselines;
// compl
void write_visibilities(const char* filename, unsigned long int num_vis, complexd* visData, experiment_parameters* experiment)
{
  FILE* fp;

  /* Open the file. */
  fp =fopen(filename, "w");
  if (!fp)
  {
      printf("ERROR: Unable to open the file %s\n", filename);
      exit(EXIT_FAILURE);
      return 1;
  }

  fprintf(fp, "# Number of stations: %d\n", experiment.num_stations);
  fprintf(fp, "# Number of frequency channels: %d\n", experiment.num_channels);
  fprintf(fp, "# Number of time samples: %d\n", experiment.num_times);
  fprintf(fp, "# Start Frequency, in Hz: %.5e\n", experiment.freq_start_hz);
  fprintf(fp, "# Frequency channel bandwidth, in Hz: %.5e\n", experiment.channel_bandwidth_hz);
  fprintf(fp, "# Reference frequency in Hz at which fluxes are measured %.5e\n", experiment.ref_frequency_hz);
  fprintf(fp, "# Accumulation time: %d\n", experiment.time_acc);
  fprintf(fp, "# Baseline threshold: %d\n", experiment.threshold);
  fprintf(fp, "# U configuration file: %c\n", experiment.filename_u);
  fprintf(fp, "# V configuration file: %c\n", experiment.filename_v);

  fprintf(fp, "# Real(Vis) \t Image(Vis)\n")

  for (i=0; i<num_vis; i++)
  {
      fprintf(fp, " %.10e \t %.10e\n", visData[i].real, visData[i].imag);
  }

  fclose(fp);

}

#ifdef __cplusplus
}
#endif