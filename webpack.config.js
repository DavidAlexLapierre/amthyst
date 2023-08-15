const path = require('path');

module.exports = {
    entry: './src/index.ts', // Entry point of your application
    output: {
        filename: 'index.js',
        path: path.resolve(__dirname, 'dist'),
    },
    resolve: {
        extensions: ['.ts', '.js'], // Allow importing TypeScript and JavaScript files
    },
    module: {
        rules: [
            {
                test: /\.ts$/,
                use: 'ts-loader',
                exclude: /node_modules/,
            },
            {
                test: /\.css$/,
                use: ['style-loader', 'css-loader'], // For handling CSS files
            },
            {
                test: /\.spec\.ts$/,
                use: 'ignore-loader'
            }
        ],
    },
};