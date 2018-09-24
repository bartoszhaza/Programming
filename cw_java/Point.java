package cw;

import static java.lang.Math.*;
import java.*;
/**
 * Representation of a point in space recorded by a GPS sensor.
 *
 * @author Nick Efford
 * @author Bartosz Haza
 */
public class Point
{
  // Constants useful for bounds checking

  private static final double MIN_LONGITUDE = -180.0;
  private static final double MAX_LONGITUDE = 180.0;
  private static final double MIN_LATITUDE = -90.0;
  private static final double MAX_LATITUDE = 90.0;
  private static final double MEAN_EARTH_RADIUS = 6.371009e+6;

  // Fields of a point

  private double longitude;   // in degrees, West is negative
  private double latitude;    // in degrees
  private double elevation;   // above sea level, in metres

  /* Two constructors that will assign latitude, longitude and elevation
  into new variables inside the Constructors */
  public Point(double newLongitude, double newLatitude)
  {
    if(longitude < MIN_LONGITUDE || longitude > MAX_LONGITUDE || latitude < MIN_LATITUDE || latitude > MAX_LATITUDE){
      throw new IllegalArgumentException("Invalid Co-ordinates: Enter a Latitude Between -90 and 90 and a Longitude between -180 and 180!");
    }
    longitude = newLongitude;
    latitude = newLatitude;
    elevation = 0.0;
  }
  public Point(double newLongitude, double newLatitude, double newElevation)
  {
    if(longitude < MIN_LONGITUDE || longitude > MAX_LONGITUDE || latitude < MIN_LATITUDE || latitude > MAX_LATITUDE){
      throw new IllegalArgumentException("Invalid Co-ordinates: Enter a Latitude Between -90 and 90 and a Longitude between -180 and 180!");
    }
    longitude = newLongitude;
    latitude = newLatitude;
    elevation = newElevation;
  }

  public String toString()
  {  
    return "("+ longitude + "," + latitude + "," + elevation +")";
  }

  /**
   * @return Longitude of this point, in degrees
   */
  public double getLongitude()
  {
    return longitude;
  }

  /**
   * @return Latitude of this point, in degrees
   */
  public double getLatitude()
  {
    return latitude;
  }

  /**
   * @return Elevation of this point above sea level, in metres
   */
  public double getElevation()
  {
    return elevation;
  }

  /**
   * Computes the great-circle distance or orthodromic distance between
   * two points on a spherical surface, using Vincenty's formula.
   *
   * @param p First point
   * @param q Second point
   * @return Distance between the points, in metres
   */
  public static double greatCircleDistance(Point p, Point q)
  {
    double phi1 = toRadians(p.getLatitude());
    double phi2 = toRadians(q.getLatitude());

    double lambda1 = toRadians(p.getLongitude());
    double lambda2 = toRadians(q.getLongitude());
    double delta = abs(lambda1 - lambda2);

    double firstTerm = cos(phi2)*sin(delta);
    double secondTerm = cos(phi1)*sin(phi2) - sin(phi1)*cos(phi2)*cos(delta);
    double top = sqrt(firstTerm*firstTerm + secondTerm*secondTerm);

    double bottom = sin(phi1)*sin(phi2) + cos(phi1)*cos(phi2)*cos(delta);

    return MEAN_EARTH_RADIUS * atan2(top, bottom);
  }
}
