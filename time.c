#include <stdio.h>
#include <time.h>

void millisToDatetime(long long milliseconds) {
    time_t seconds = milliseconds / 1000;
    struct tm *datetime = localtime(&seconds);

    // ������ں�ʱ����Ϣ
    printf("\nת��������ں�ʱ��Ϊ��%d-%02d-%02d %02d:%02d:%02d\n",
           datetime->tm_year + 1900, datetime->tm_mon + 1, datetime->tm_mday,
           datetime->tm_hour, datetime->tm_min, datetime->tm_sec);
}

int main() {
    printf("\n��ʼʱ��2024.3.30����������룺1��ʾ�ӣ�2��ʾ��,3Ϊ�˳���");
    for (;;) {
        long long currentTime = 1711804190489LL; // ʹ��LL��׺ȷ��������ʶ��Ϊlong long����
        long long date2 = 86400000LL; // һ��ĺ�����
        int code, days;

        scanf("%d", &code);
        if (code == 3) {
            break;
        }
        switch (code) {
            case 1:
                printf("������Ҫ�ӵ�������");
                scanf("%d", &days);
                currentTime += days * date2;
                printf("ʱ��Ϊ��%lld\n", currentTime);
                printf("��10����Ϊ��%lld\n", currentTime + 600000);

                millisToDatetime(currentTime);
                break;

            case 2:
                printf("������Ҫ����������");
                scanf("%d", &days);
                currentTime -= days * date2;
                printf("ʱ��Ϊ��%lld\n", currentTime);
                printf("��10����Ϊ��%lld\n", currentTime + 600000);

                millisToDatetime(currentTime);
                break;

            default:
                printf("��Ч�Ĳ����롣\n");
                break;
        }
    }
    return 0;
}

