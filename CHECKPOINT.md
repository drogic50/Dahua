# Project Checkpoint: ANPR Plate Relay Service

## Current Status

- **Visual Studio Solution**: Two projects (`AnprPlateRelayService` Windows Service, `AnprPlateRelayService.ConsoleTest` WinForms manual UI)
- **Config**: All service and socket settings in `anpr.ini`
- **Socket Helper**: Robust retry/timeout logic in both service and console test, using INI config
- **MySQL Integration**: Both service and UI insert full plate event details to the `tblCameraLog` table, including snapshot image in `snapshot_jpg` column
- **Windev Integration**: Both service and UI relay plate data via socket and await OK response
- **Dahua Integration**: Event-based processing via relay service, ready for SDK integration
- **Snapshot Image**: Captured image is retrieved and stored in MySQL:
    - If image is >2MB, it is resized/compressed to ≤2MB using JPEG format.

## Database Schema (MySQL)

See `schema.sql` for the full definition.

**Table:** `tblCameraLog`
| Column         | Type         | Description                    |
|----------------|--------------|--------------------------------|
| id             | INT, PK      | Auto-increment ID              |
| camera_ip      | VARCHAR(64)  | Camera IP Address              |
| plate_number   | VARCHAR(32)  | Plate Number                   |
| timestamp      | DATETIME     | Event timestamp                |
| plate_color    | VARCHAR(32)  | Plate Color                    |
| plate_type     | VARCHAR(32)  | Plate Type                     |
| vehicle_type   | VARCHAR(32)  | Vehicle Type                   |
| vehicle_color  | VARCHAR(32)  | Vehicle Color                  |
| vehicle_size   | INT          | Vehicle Size                   |
| lane           | INT          | Lane Number                    |
| device_address | VARCHAR(255) | Camera Device Address          |
| bbox_left      | INT          | Bounding Box Left              |
| bbox_top       | INT          | Bounding Box Top               |
| bbox_width     | INT          | Bounding Box Width             |
| bbox_height    | INT          | Bounding Box Height            |
| file_index     | INT          | File Index                     |
| file_count     | INT          | File Count                     |
| group_id       | INT          | Group ID                       |
| snapshot_jpg   | LONGBLOB     | Plate snapshot as JPEG, ≤2MB   |

## Snapshot Storage Logic

- The relay/service retrieves the ANPR event image buffer.
- If the buffer size is > 2MB, it is recompressed to JPEG, quality reduced as needed, for ≤2MB.
- The resulting JPEG byte array is stored in the `snapshot_jpg` column.

## Next Steps

- **Dahua SDK integration**: Replace `DahuaSdk.Login` and event subscription stubs with real SDK calls and image extraction.
- **Windev receiver testing**: Confirm Windev parses/acks the full extended message format.
- **Deployment & Install**: Service installer, .exe packaging, first run documentation.
- **(Optional) Export/Reporting**: Query/export images and data from the database.

---

**You may now safely continue development from this checkpoint.**