CREATE TABLE tblCameraLog (
    id INT AUTO_INCREMENT PRIMARY KEY,
    cameraip VARCHAR(64),
    platenumber VARCHAR(32),
    timestamp DATETIME,
    imagedata LONGBLOB
);