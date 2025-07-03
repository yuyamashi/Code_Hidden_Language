# Use an official lightweight C build image
FROM gcc:latest

# Set the working directory
WORKDIR /workspace

# Copy the code into the container
COPY . .

# Default command: show usage
CMD ["/bin/bash"] 