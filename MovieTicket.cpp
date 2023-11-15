#include <iostream>
#include <vector>
#include <iomanip>

class Movie {
public:
    std::string title;
    int availableSeats;
    float price;

    Movie(std::string title, int availableSeats, float price)
        : title(std::move(title)), availableSeats(availableSeats), price(price) {}
};

class Seat {
public:
    int row;
    char seatNumber;
    bool isBooked;

    Seat(int row, char seatNumber)
        : row(row), seatNumber(seatNumber), isBooked(false) {}
};

class Theater {
public:
    std::vector<std::vector<Seat>> seats;

    Theater(int rows, int seatsPerRow) {
        for (int i = 0; i < rows; ++i) {
            std::vector<Seat> row;
            for (char j = 'A'; j < char('A' + seatsPerRow); ++j) {
                row.emplace_back(i + 1, j);
            }
            seats.push_back(row);
        }
    }

    void displayAvailableSeats() {
        std::cout << "Available Seats:\n";
        for (const auto &row : seats) {
            for (const auto &seat : row) {
                if (!seat.isBooked) {
                    std::cout << "Row: " << seat.row << " Seat: " << seat.seatNumber << "\n";
                }
            }
        }
    }

    bool bookSeat(int row, char seatNumber) {
        Seat &selectedSeat = seats[row - 1][seatNumber - 'A'];
        if (!selectedSeat.isBooked) {
            selectedSeat.isBooked = true;
            return true;
        }
        return false;
    }

    float calculateTotalCost(int numOfSeats, float pricePerSeat) {
        return numOfSeats * pricePerSeat;
    }
};

int main() {
    Movie movie("Avengers: Endgame", 5, 10.0); // Example movie with 5 available seats and $10 per seat
    Theater theater(5, 8); // Creating a theater with 5 rows and 8 seats per row

    std::cout << "Welcome to the Movie Ticket Booking System\n";
    std::cout << "Movie: " << movie.title << ", Price: $" << movie.price << " per seat\n\n";

    theater.displayAvailableSeats();

    int selectedRow;
    char selectedSeat;
    int numSeatsToBook;

    std::cout << "\nEnter row number and seat letter to book (e.g., 3 A): ";
    std::cin >> selectedRow >> selectedSeat;

    if (selectedRow < 1 || selectedRow > 5 || selectedSeat < 'A' || selectedSeat > 'H') {
        std::cout << "Invalid seat selection!\n";
        return 1;
    }

    std::cout << "Enter the number of seats to book: ";
    std::cin >> numSeatsToBook;

    if (numSeatsToBook > movie.availableSeats) {
        std::cout << "Sorry, not enough seats available for your booking.\n";
        return 1;
    }

    float totalCost = 0.0;
    for (int i = 0; i < numSeatsToBook; ++i) {
        if (theater.bookSeat(selectedRow, selectedSeat + i)) {
            totalCost += movie.price;
        } else {
            std::cout << "Seat " << char(selectedSeat + i) << " in row " << selectedRow << " is already booked.\n";
            return 1;
        }
    }

    std::cout << "Seats booked successfully!\n";
    std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

    return 0;
}
