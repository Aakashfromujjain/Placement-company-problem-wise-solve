import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Hotel[] hotels = new Hotel[4];

        // Read 4 Hotel objects
        for (int i = 0; i < 4; i++) {
            int hotelId = sc.nextInt();
            sc.nextLine(); // consume newline
            String hotelName = sc.nextLine();
            String dateOfBooking = sc.nextLine();
            int noOfRoomsBooked = sc.nextInt();
            sc.nextLine(); // consume newline
            String wifiFacility = sc.nextLine();
            double totalBill = sc.nextDouble();
            sc.nextLine(); // consume newline
            
            hotels[i] = new Hotel(hotelId, hotelName, dateOfBooking, noOfRoomsBooked, wifiFacility, totalBill);
        }

        // Read search parameters
        String month = sc.nextLine();
        String wifiOption = sc.nextLine();

        // Method 1: Find total rooms booked in given month
        int roomsBooked = noOfRoomsBookedInGivenMonth(hotels, month);
        if (roomsBooked > 0) {
            System.out.println(roomsBooked);
        } else {
            System.out.println("No rooms booked in the given month");
        }

        // Method 2: Find hotel with second highest bill for given wifi option
        Hotel secondHighestHotel = searchHotelByWifiOption(hotels, wifiOption);
        if (secondHighestHotel != null) {
            System.out.println(secondHighestHotel.getHotelId());
        } else {
            System.out.println("No such option available");
        }
        
        sc.close();
    }

    public static int noOfRoomsBookedInGivenMonth(Hotel[] hotels, String month) {
        int totalRooms = 0;
        
        for (Hotel h : hotels) {
            // Split the date "dd-mon-yyyy" to extract the month at index 1
            String[] dateParts = h.getDateOfBooking().split("-");
            if (dateParts.length == 3) {
                String bookingMonth = dateParts[1];
                // Case insensitive check
                if (bookingMonth.equalsIgnoreCase(month)) {
                    totalRooms += h.getNoOfRoomsBooked();
                }
            }
        }
        
        return totalRooms;
    }

    public static Hotel searchHotelByWifiOption(Hotel[] hotels, String wifiOption) {
        int count = 0;
        
        // Count how many hotels match the wifi option
        for (Hotel h : hotels) {
            if (h.getWifiFacility().equalsIgnoreCase(wifiOption)) {
                count++;
            }
        }
        
        // If no matching hotels found
        if (count == 0) {
            return null;
        }
        
        // Create an array to hold matching hotels
        Hotel[] matchedHotels = new Hotel[count];
        int index = 0;
        for (Hotel h : hotels) {
            if (h.getWifiFacility().equalsIgnoreCase(wifiOption)) {
                matchedHotels[index++] = h;
            }
        }
        
        // Sort the matched hotels in descending order based on totalBill
        for (int i = 0; i < matchedHotels.length - 1; i++) {
            for (int j = 0; j < matchedHotels.length - i - 1; j++) {
                if (matchedHotels[j].getTotalBill() < matchedHotels[j + 1].getTotalBill()) {
                    Hotel temp = matchedHotels[j];
                    matchedHotels[j] = matchedHotels[j + 1];
                    matchedHotels[j + 1] = temp;
                }
            }
        }
        
        // According to the problem note, if there are matching elements, there are at least 2.
        // The second highest will be at index 1 after descending sort.
        return matchedHotels[1];
    }
}

class Hotel {
    private int hotelId;
    private String hotelName;
    private String dateOfBooking;
    private int noOfRoomsBooked;
    private String wifiFacility;
    private double totalBill;

    // Parameterized constructor
    public Hotel(int hotelId, String hotelName, String dateOfBooking, int noOfRoomsBooked, String wifiFacility, double totalBill) {
        this.hotelId = hotelId;
        this.hotelName = hotelName;
        this.dateOfBooking = dateOfBooking;
        this.noOfRoomsBooked = noOfRoomsBooked;
        this.wifiFacility = wifiFacility;
        this.totalBill = totalBill;
    }

    // Getters and Setters
    public int getHotelId() {
        return hotelId;
    }

    public void setHotelId(int hotelId) {
        this.hotelId = hotelId;
    }

    public String getHotelName() {
        return hotelName;
    }

    public void setHotelName(String hotelName) {
        this.hotelName = hotelName;
    }

    public String getDateOfBooking() {
        return dateOfBooking;
    }

    public void setDateOfBooking(String dateOfBooking) {
        this.dateOfBooking = dateOfBooking;
    }

    public int getNoOfRoomsBooked() {
        return noOfRoomsBooked;
    }

    public void setNoOfRoomsBooked(int noOfRoomsBooked) {
        this.noOfRoomsBooked = noOfRoomsBooked;
    }

    public String getWifiFacility() {
        return wifiFacility;
    }

    public void setWifiFacility(String wifiFacility) {
        this.wifiFacility = wifiFacility;
    }

    public double getTotalBill() {
        return totalBill;
    }

    public void setTotalBill(double totalBill) {
        this.totalBill = totalBill;
    }
}
