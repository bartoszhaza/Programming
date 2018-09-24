package cw;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.io.FileWriter;
import java.io.Writer;
import java.io.BufferedWriter;
public class Track{

	ArrayList<Point> tracker; // This will create a point tracker

	// Constructor track that will make "tracker" a point in the ArrayListy
	Track(){ 

		tracker = new ArrayList<Point>();
	}

	// A point will be added to the tracker
	public void add(Point a){

		tracker.add(a);
	}

	// This will return the tracker size
	public int size(){
		
		return tracker.size();
	}

	// Calculate the distance of th great circle
	public double totalDistance(){

		double distance = 0.0; // Variable for the distance
		int i; // This will loop through the tracks

		// This will loop through the tracker and not stop as long as i is less than the size of the tracker - 1
		for(i = 0; i < tracker.size() - 1; i++)
		{
			distance += Point.greatCircleDistance(tracker.get(i), tracker.get(i+1)); // Distance of the grat circle working out
		}

		return distance; // Returns the variable distance
	}

	// Method read that will read point details froma a file
	public void read(String read_file) throws IOException {
		
		// Read the file
		FileReader file = new FileReader(read_file);

		// Scan the file
		Scanner scanner = new Scanner(file); // New scanner that will read the file

		// The while loop will loop through the scanner and create a point
		while(scanner.hasNextDouble()){

			double longitude = scanner.nextDouble(); // Scanner for longotide
			double latitude = scanner.nextDouble(); // Scanner for latitude
			double elevation = scanner.nextDouble(); // Scanner for elevation
			Point newPoint = new Point(longitude, latitude, elevation); // New points longitude, latitude and elevation
			add(newPoint); // This will add a new point
		}
		scanner.close(); // Close the the file that is read
	}

	// Constructor that calls the read method
	public Track(String file) throws IOException{
		tracker = new ArrayList<Point>();
		read(file); // This will read method "read"
	}

	// Method for the lowestPoint
	public Point lowestPoint(){
		int i; // Variable to loop through the tracker
		double elevationMax = 999.0; // Elevation set to the highest number so anything that is less than the max is the min
		Point p = new Point(0.0, 0.0, 0.0); // Empty point
		int trackSize = tracker.size(); // trackSize is just the size of the tracker

		/**********************************************************************************************************
		* For loop that loops through the trackSize and if i is less than trackSize it will keep incrementing     *
		* the if loop gives a condition that if the tracker.get(i) the i wich was used for incrementing with      *
		* getElevation() is less than the elevationMax then p = tracker.get(i) and elevationMax is                *
		* tracker.get(i).getElevation(), the same principle is applied to the highestPoint the difference is that *
		* the highestPoint's if statement condition is different as we are trying to fin the opposite hence       *
		* why the elevationMin variable is set to 0.00 as we are trying to find the opposite                      *
		***********************************************************************************************************/
		for(i = 0; i < trackSize; i++){
			if(tracker.get(i).getElevation() < elevationMax){
				p = tracker.get(i);
				elevationMax = tracker.get(i).getElevation();
			}
		}
		return p; // Return p the point that was created this will give the new coordinates
	}

	// Method for the highestPoint
	public Point highestPoint(){
		int i;
		double elevationMin = 0.00;
		Point p = new Point(0.0, 0.0, 0.0);
		int trackSize = tracker.size();

		for(i = 0; i < trackSize; i++){
			if(tracker.get(i).getElevation() > elevationMin){
				p = tracker.get(i);
				elevationMin = tracker.get(i).getElevation();
			}
		}
		return p;
	}
	// This method will find the nearestPointTo, first the lowest greatCircleDistance
	// will be found, the loop will loop through until there is no lower coordinate
	public Point nearestPointTo(Point target){
		double minDistance = Point.greatCircleDistance(target, tracker.get(0));
		Point l = new Point(0.0, 0.0); // New point with longitude and latitude set to 0
		for(Point p : tracker){
			double d = Point.greatCircleDistance(target, p);
			// If the minDistance is greater than d then the minDistance is d
			if(minDistance > d){
				minDistance = d;
				l = p; // Assign l to Point p
			}
		}
		return l; // Return l that was assigned to the Point p
	}

	// write method with a parameter of a String that i have called gpx_file
	// the method will output a .gpx file that will be then used to show the 	
	// path on the GPSVisualizer
	public void write(String gpx_file) throws FileNotFoundException, IOException{
		FileWriter fileopen = new FileWriter(gpx_file); // Open file with writer
		Writer out = new BufferedWriter(fileopen); // New writer

		// Longitude, latitude and elevation set to 0
		double lon = 0;
		double lat = 0;
		double ele = 0;


		int slength = gpx_file.length(); // New variable that will be assigned to the length of String gpx_file
		String s = "gpx"; // String for gpx
		if(gpx_file.charAt(slength-3) == s.charAt(0))
		{
			// This will write the output of the gpx
			out.write("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\n");
			out.write("<gpx>\n");
			out.write("<trk>\n");
			out.write("<name>gps.gpx</name>\n");
			out.write("<trkseg>\n");
			for (Point p : tracker) 
			{
				lon = p.getLongitude();
				lat = p.getLatitude();
				ele = p.getElevation();
				out.write("<trkpt lat=" + "\"" + lat + "\" lon=\"" + lon + "\">\n" +  "<ele>" + ele + "</ele>\n" + "</trkpt>\n");
			}
			out.write("</trkseg>\n");
			out.write("</trk>\n");
			out.write("</gpx>\n");
	}
	out.close(); //Close the file
}
}