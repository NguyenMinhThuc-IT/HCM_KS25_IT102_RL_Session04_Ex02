#include <stdio.h>

int main(void) {
    int total_orders = 0;
    
    int successful_orders = 0;
    int failed_orders = 0;
    long long total_revenue = 0;
    long long max_order_value = 0;

    printf("=== POS SYSTEM - SHIFT RECONCILIATION ===\n");
    printf("Enter total number of orders in shift: ");
    if (scanf("%d", &total_orders) != 1) {
        printf("Error: Invalid input data!\n");
        return 0;
    }

    for (int i = 1; i <= total_orders; i++) {
        long long base_price = 0;
        char size_char = ' ';
        int topping_count = 0;
        int is_gold_member = 0;

        printf("\n-----------------------------------\n");
        printf(">>> ENTER ORDER DETAILS %d/%d <<<\n", i, total_orders);
        
        printf("1. Enter base price for Size S (VND): ");
        scanf("%lld", &base_price);

        printf("2. Enter beverage Size (S, M, L): ");
        scanf(" %c", &size_char);

        printf("3. Enter number of toppings: ");
        scanf("%d", &topping_count);

        printf("4. Gold Member? (1: Yes, 0: No): ");
        scanf("%d", &is_gold_member);

        if (topping_count < 0) {
            printf("\n[SECURITY WARNING] Negative topping quantity detected (%d)! Unauthorized access or POS error.\n", topping_count);
            printf("[NOTICE] EMERGENCY SHIFT SHUTDOWN! Generating accumulated report...\n");
            break;
        }

        if (base_price <= 0 || (size_char != 'S' && size_char != 's' &&
                                size_char != 'M' && size_char != 'm' &&
                                size_char != 'L' && size_char != 'l')) {
            printf("\n[INVALID ORDER] Order #%d has invalid base price or size!\n", i);
            printf("[SYSTEM] Skipping this order and moving to the next one.\n");
            failed_orders++;
            continue;
        }

        long long size_surcharge = 0;
        if (size_char == 'M' || size_char == 'm') {
            size_surcharge = 6000;
        } else if (size_char == 'L' || size_char == 'l') {
            size_surcharge = 10000;
        }

        long long topping_surcharge = (long long)topping_count * 8000;
        long long total_before_discount = base_price + size_surcharge + topping_surcharge;
        long long final_payment = total_before_discount;

        if (is_gold_member == 1) {
            final_payment = (long long)(total_before_discount * 0.90);
        }

        successful_orders++;
        total_revenue += final_payment;

        if (final_payment > max_order_value) {
            max_order_value = final_payment;
        }

        printf("-> Payment successful! Amount: %lld VND\n", final_payment);
    }

    printf("\n==================================================\n");
    printf("         SHIFT REVENUE SUMMARY REPORT             \n");
    printf("==================================================\n");
    printf("Total valid orders     : %d\n", successful_orders);
    printf("Total invalid/skipped  : %d\n", failed_orders);
    printf("Total actual revenue   : %lld VND\n", total_revenue);
    printf("Highest order value    : %lld VND\n", max_order_value);
    printf("==================================================\n");

    return 0;
}