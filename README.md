# OUI-SNC++

**OUI-SNC++** is a console application in C++ that manages a catalog of routes, whether they are simple or composed. It offers features such as displaying, searching, adding, saving, and loading routes from files.

## Features

- **Display Routes**: Shows all routes currently recorded in the catalog.
- **Search for Routes**: Allows searching for routes based on a departure city and an arrival city.
- **Add Routes**:
  - **Simple Route**: A direct route between a departure city and an arrival city, via a mode of transportation.
  - **Composed Route**: A route consisting of several successive stages (multiple simple routes chained together).
- **Save Catalog**: Saves the routes to a file with options to filter by route type and specific cities.
- **Load Catalog**: Loads routes from a file with similar filtering options to those of saving.

## Installation

1. **Clone the project**:
   ```bash
   git clone https://github.com/swan-maillard/INSA-3A-TripManager.git
   ```

2. **Access the project directory**:
   ```bash
   cd INSA-3A-TripManager
   ```

3. **Compile the project**:
   ```bash
   make
   ```

4. **Launch the application**:
   ```bash
   ./trajets
   ```

## Usage

Once the application is launched, an interactive menu allows you to navigate between different options:

1. **Display Routes**: Shows all routes recorded in the catalog.
2. **Search for a Route**: Allows you to search for a route by specifying the departure city and the arrival city.
3. **Add a Route**:
   - **Simple Route**: Add a direct route by providing the information for the departure city, arrival city, and mode of transportation.
   - **Composed Route**: Add a composed route by specifying the different stages (cities and modes of transportation).
4. **Load a File**: Loads routes from an existing file.
5. **Save to a File**: Saves the current catalog to a file with filtering options (route type, departure city, arrival city, etc.).
6. **Exit**: Exits the application.

## Project Structure

- **src/**: Contains the C++ source files (.cpp).
- **include/**: Contains the header files (.h).
- **Makefile**: Automates the compilation and management of the project.

## Makefile Commands

The project includes a Makefile to simplify compilation and file management. Here are some useful commands:

- `make`: Compiles the project and generates the executable.
- `make dev`: Compiles the project in development mode with debugging options.
- `make run`: Compiles and runs the application.
- `make clean`: Removes generated object files.
- `make fclean`: Removes object files as well as the executable.
- `make info`: Displays information about the project structure.

## Authors

- **Swan Maillard** (maillard.swan@gmail.com)
- **Sarah Malard** (sarah.malard@insa-lyon.fr)

## License

This project is licensed under the MIT License. Please refer to the `LICENSE` file for more information.
