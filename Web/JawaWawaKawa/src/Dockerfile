FROM php:fpm
WORKDIR /app/src

RUN apt-get update && apt-get install -y \
    libsqlite3-dev \
    xxd \
    curl \
    bc \
    sqlite3 \
    unzip \
    && curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer
COPY --from=composer:latest /usr/bin/composer /usr/bin/composer
COPY src/ /app/src/
CMD ["start"]