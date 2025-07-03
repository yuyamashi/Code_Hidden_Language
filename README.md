# CODE: The Hidden Language of Computer Hardware and Software [[Link](https://codehiddenlanguage.com/)]

Chapter 6. Logic with Switches [[Link](https://codehiddenlanguage.com/Chapter06/)]

---

## Running C Code with Docker

You can use Docker to compile and run the C code examples in this repository without installing a compiler on your local machine.

### 1. Build the Docker Image

```sh
docker build -t codehiddenlanguage-c .
```

### 2. Run a Container with Interactive Shell

```sh
docker run -it --rm -v "$PWD":/workspace codehiddenlanguage-c
```

### 3. Compile and Run C Programs Inside the Container

For example, to compile and run the AND logic example:

```sh
gcc chap6_Logic_with_Switches/and.c -o chap6_Logic_with_Switches/and
./chap6_Logic_with_Switches/and
```

You can do the same for other C files in the `chap6_Logic_with_Switches` directory.

