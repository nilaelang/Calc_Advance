// Function to calculate sine of an angle in degrees
float calculateSine(float angleDegrees) {
    float angleRadians = angleDegrees * (M_PI / 180); // Convert degrees to radians
    return sin(angleRadians);
}

// Function to calculate cosine of an angle in degrees
float calculateCosine(float angleDegrees) {
    float angleRadians = angleDegrees * (M_PI / 180); // Convert degrees to radians
    return cos(angleRadians);
}

// Function to calculate tangent of an angle in degrees
float calculateTangent(float angleDegrees) {
    float angleRadians = angleDegrees * (M_PI / 180); // Convert degrees to radians
    return tan(angleRadians);
}


// ... (previous code remains unchanged)

case 1:
    printf("Basic Functions\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Sine\n6. Cosine\n7. Tangent\n");
    printf("Enter your operation choice (1-7): ");
    int operation;
    scanf("%d", &operation);

    printf("Enter angle in degrees (if trigonometric function selected): ");
    float angle;
    scanf("%f", &angle);

    switch (operation) {
        case 1:
            // Existing addition code
            break;
        case 2:
            // Existing subtraction code
            break;
        case 3:
            // Existing multiplication code
            break;
        case 4:
            // Existing division code
            break;
        case 5:
            printf("Sine: %.4f\n", calculateSine(angle));
            break;
        case 6:
            printf("Cosine: %.4f\n", calculateCosine(angle));
            break;
        case 7:
            printf("Tangent: %.4f\n", calculateTangent(angle));
            break;
        default:
            printf("Invalid operation choice.\n");
    }
    break;

// ... (rest of the code remains unchanged)

