#include <stdio.h>
#include <stdlib.h>
#include <glusterfs/api/glfs.h>
#include <glusterfs/api/glfs-handles.h>

int
main(int argc, char *argv[])
{
    glfs_t *fs = NULL;
    glfs_fd_t *fd = NULL;
    int ret = 1;
    off_t size = 0;

    if (argc != 6) {
        fprintf(stderr,
                "Syntax: %s <host> <volname> <file-path> <log-file> <size>\n",
                argv[0]);
        return 1;
    }

    fs = glfs_new(argv[2]);
    if (!fs) {
        fprintf(stderr, "glfs_new: returned NULL\n");
        return 1;
    }

    ret = glfs_set_volfile_server(fs, "tcp", argv[1], 24007);
    if (ret != 0) {
        fprintf(stderr, "glfs_set_volfile_server: returned %d\n", ret);
        goto out;
    }
    ret = glfs_set_logging(fs, argv[4], 7);
    if (ret != 0) {
        fprintf(stderr, "glfs_set_logging: returned %d\n", ret);
        goto out;
    }
    ret = glfs_init(fs);
    if (ret != 0) {
        fprintf(stderr, "glfs_init: returned %d\n", ret);
        goto out;
    }

    fd = glfs_open(fs, argv[3], O_RDWR);
    if (fd == NULL) {
        fprintf(stderr, "glfs_open: returned NULL\n");
        goto out;
    }

    size = strtol(argv[5], NULL, 10);
    if (size < 0) {
        fprintf(stderr, "Wrong size %s", argv[5]);
        goto out;
    }
    ret = glfs_zerofill(fd, 0, size);
    if (ret <= 0) {
        fprintf(stderr, "glfs_zerofill: returned %d\n", ret);
        goto out;
    }

    ret = 0;

out:
    if (fd)
        glfs_close(fd);
    glfs_fini(fs);
    return ret;
}
