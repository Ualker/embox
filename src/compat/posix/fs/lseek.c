/**
 * @file
 *
 * @date Nov 15, 2013
 * @author: Anton Bondarev
 */
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


#include <fs/kfile.h>
#include <fs/file_desc.h>


extern const struct idesc_ops task_idx_ops_file;
off_t lseek(int fd, off_t offset, int origin) {
	struct file_desc *desc;

	desc = file_desc_get(fd);
	assert(desc);


	if (desc->idesc.idesc_ops != &task_idx_ops_file) {
		return -EBADF;
	}

	return kseek(desc, offset, origin);
}
