package cw;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;
import java.io.FileWriter;
import java.io.Writer;
import java.io.BufferedWriter;

public class Test{
	public static void main(String[] args) throws FileNotFoundException, IOException{

		// Banner to divide each sectiob

		// Five coordinates will be created and assigned for latitude and longitude from an actual map
		Point point1 = new Point(-1.5526461900675514, 53.80545240454384);
		Point point2 = new Point(-1.53533935546875, 53.79740645735382);
		Point point3 = new Point(-1.51336669921875, 53.77874646437006);
		Point point4 = new Point(-1.479034423828125, 53.75845444856315);
		Point point5 = new Point(-1.415863037109375, 53.733278725764414);
		Point target = new Point (-1.5492, 53.7997);

		Track track1 = new Track(); // First track for the basic solutiob
		Track track2 = new Track(); // Second track object for the intermediate solution

		// The point objects are added to the track object
		track1.add(point1);
		track1.add(point2);
		track1.add(point3);
		track1.add(point4);
		track1.add(point5);

		track2.read("walk.txt"); // Second track that will be used for the indermediate solution 
		track2.write("out.gpx"); // Write an .gpx file

		// Print statements for printing out the results for all of the parts
		System.out.printf("//////////////////////////// BASIC SOLUTION ////////////////////////////\n");
		System.out.println(track1.size() + " points in track");
		System.out.println("Total distance = " + track1.totalDistance() + " Meters");
		System.out.printf("//////////////////////// INTERMEDIATE SOLUTION /////////////////////////\n");
		System.out.println(track2.size() + " points in track");
		System.out.println("Total distance = " + track2.totalDistance() / 1000 + " Kilometers");
		System.out.println("Lowest point is " + track2.lowestPoint());
		System.out.println("Highest point is " + track2.highestPoint());
		System.out.printf("////////////////////////// ADVANCED SOLUTION ///////////////////////////\n");
		System.out.println("Point nearest " + track2.nearestPointTo(target));
	}	
}