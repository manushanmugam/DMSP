# DMSP
EDR file format
data format for density.txt
		col1 -> Primary Plasma Density (/cm^3)
		col2 ->	Horizontal Ion Drift Velocities (m/s)
		col3 -> Vertical Ion Drift Velocities (m/s)
		col4 -> DM ion Density (ion/cm^3).

data format for EPA_RPAdata.txt
		col1-> Sweep center time (UT, seconds)
		col2-> Electron density (el/cm^3)
		col3-> Electron temperature (degrees K) 
		col4-> Satellite potential (volts)
		col6-> Analysis qualifier
		col7-> EP photo-electron surrogate value.
		col8-> Sweep center time (UT, seconds) 
		col9-> O+ density (ion/cm^3 )
		col10-> Total (H+ + He+) density (ion/cm^3)
		col11-> Light ion flag 0 - No light ion;1 - Light ion is H+;
									 2 - Light ion is He+; 3+ - = 3 + 10000 x (H+ fraction)
		col12-> Ion Temperature (degrees K)
		col13-> Ram ion drift Velocity (m/s)
		col14-> Analysis Qualifier 0 - Analysis terminated unsuccessfully
															 1 - Successful analysis
		col15-> RPA-derived total ion density.

data format for Ephemeris.txt
		col1: Geographic latitude (degrees, north)
		col2: Geographic longitude (degrees, east)
		col3: Apex latitude (degrees, north)
		col4: Apex longitude (degrees, east)
		col5: Apex local time (hours)
		col6: Satellite altitude (km)

data format for record.txt
		col1: Record number
		col2: EDR Number 
		col3: Satellite Flight ID 
		col4: Date (YYYYMMDD)
		col5: Time (HHMM)
